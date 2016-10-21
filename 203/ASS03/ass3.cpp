/*********************************************************************************
 * Filename: ass3.cpp
 * Name & Student No.: Yanhong Ben, 4845675
 * ASS No: 3
 * File Description: practice and improve Dijkstra's algorithm
 *********************************************************************************/

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;


const int MAXSIZE = 50; //no more than 50 nodes in the graph

int countNodes = 0; //count how many nodes
int countEdges = 0; //count how many edges
int sourceNode = 0; //store the source node
int destNode = 0; //store the destination node

struct Node
{
    int index; //store the index of the nodes
    double nodeX; //store the x-coordinate of the nodes
    double nodeY; //store the y-coordinate of the nodes
};

struct Triples
{
    int fromNode; //store the start node of each edge
    int toNode; //store the end node of each edge
    double edgeCost; //store the edge cost of each edge
};

struct Node nodes[MAXSIZE];
struct Triples* trips; //dynamic array to store the edge

double graphic[MAXSIZE][MAXSIZE]; //temp dimensional array for Dijkstra algorithm
double d[MAXSIZE]; //temp array for Dijkstra algorithm
double p[MAXSIZE]; //temp array for Dijkstra algorithm

void readFile()
{
    ifstream fin;
    char filename[20];
    cout << "Please input filename: ";
    cin.getline(filename, 20, '\n');
    fin.open(filename);
    while (!fin.good())
    {
       cout << "Wrong file name. Please try again: ";
       cin.getline(filename, 20, '\n');
       fin.open(filename);
    }
    fin >> countNodes;
    if(fin.good())
    {
        for (int i=0; i<countNodes; i++)
        {
            fin >> nodes[i].index >> nodes[i].nodeX >> nodes[i].nodeY;
        }
        fin >> countEdges;
        trips = new Triples[countEdges];
        for (int i=0; i<countEdges; i++)
        {
            fin >> trips[i].fromNode >> trips[i].toNode >> trips[i].edgeCost;
        }
    }
    fin >> sourceNode >> destNode;
    fin.close();
}


//================= Heap functions ==================
void swap(double &a, double &b)
{
    double temp;
    temp = a;
    a = b;
    b = temp;
}

void swap(int& id1, int& id2)
{
    int temp;
    temp = id1;
    id1 = id2;
    id2 = temp;
}

void sift_up(double *heap, int* index, int i)
{
    if (i == 0)
        return;
    int p = (i-1) / 2;
    if (heap[p] <= heap[i])
        return;
    else
    {
        swap(heap[i], heap[p]);
        swap(index[i], index[p]);
        sift_up(heap, index, p);
    }
}

void sift_down(double *heap, int *index, int i, int size)
{
    int c = i * 2 + 1;
    if (c < size-1)
        if (heap[c] > heap[c+1])
            c++;
    if (c <= size-1)
    {
        if (heap[i] > heap[c])
        {
            swap(heap[i], heap[c]);
            swap(index[i], index[c]);
            sift_down(heap, index, c, size);
        }
    }
    else
        return;
}

//================ Run ========================
void initialize()
{
    //initialize grahic array with -1 which is big enough to avoid sift down and up by heap sort
    for (int row=0; row<countNodes; row++)
    {
        for (int col=0; col<countNodes; col++)
            graphic[row][col] = 999;
    }
    
    //initialize graphic array with data read from the file
    int i = 0;
    while (i < countEdges)
    {
        graphic[trips[i].toNode-1][trips[i].fromNode-1] = trips[i].edgeCost;
        graphic[trips[i].fromNode-1][trips[i].toNode-1] = trips[i].edgeCost;
        i++;
    }

    for (int i=0; i<countNodes; i++)
    {
        d[i] = 0;
        p[i] = 0;
    }
}

void solution1()
{
    initialize();

    //set a boolean array to flag if node has been visited
    bool visited[countNodes];
    for (int i=0; i<countNodes; i++) //initialize visited array
        visited[i] = false;
    
    //set index array to identify the distance
    int index[countNodes];
    for (int i=0; i<countNodes; i++)
        index[i] = i;
    
    //marked source node to be visited
    visited[sourceNode-1] = true;
    
    //for i=1 to n do
    double copy_d[countNodes]; //make a copy d array to do heap sort to prevent data change in d array
    for (int i=0; i<countNodes; i++)
    {
        d[i] = graphic[sourceNode-1][i]; //d[i] = L[source, i]
        copy_d[i] = graphic[sourceNode-1][i];
        sift_up(copy_d, index, i); //inset d array and index array into a heap and sorted
        p[i] = sourceNode - 1; //p[i] = source
    }
    
    //repeat while destination is not visited
    int v = 0;
    int w = 0;
    int countNotSelected = countNodes;
    while (v != destNode - 1)
    {
        //v = the index of the minimum d[v] not yet selected
        v = index[0];
        //throw notifcation there is no path between the nodes
        if (d[v] == 999) 
        {
            cout << "No edge between nodes." << endl;
            return;
        }
        
        //mark v as visited
        visited[v] = true;
        
        //for each w not visited do
        if(v != destNode - 1)
        {
            copy_d[0] = copy_d[countNotSelected-1];
            index[0] = index[countNotSelected-1];
            sift_down(copy_d, index, 0, countNotSelected);
            countNotSelected--;

            for (w=0; w<countNodes; w++)
            {
                if (visited[w] == false)
                {
                    if (d[w] > d[v] + graphic[v][w])
                    {
                        d[w] = d[v] + graphic[v][w];
                        int i = 0;
                        while (i < countNodes && index[i] != w) //find the w in the index array
                            i++;
                        copy_d[i] = d[v] + graphic[w][v]; //change copy array as well
                        sift_up(copy_d, index, i);
                        p[w] = v;
                    }
                }
            }
        }
    }
    
    // get the path from the path array
    int shortestPath[countNodes];
    int k = 0;
    int j = destNode-1;
    while (j != sourceNode-1)
    {
        shortestPath[k] = j;
        j = p[j];
        k++;
    }
    shortestPath[k] = sourceNode - 1;
    
    cout << endl;
    cout << "============================== Result ==============================" << endl;
    cout << "The length of the shortest path from solution 1: " << d[destNode - 1] << endl;
    cout << "The Path from solution 1: ";
    for (int i=k; i>0; i--)
        cout << shortestPath[i]+1 << "-->";
    cout << shortestPath[0]+1;
    cout << endl;
    cout << "The number of additional nodes in the solution tree for solution 1: " << endl;
    for (int i=0; i<=k; i++)
        visited[shortestPath[i]] = false;
    for (int i=0; i<countNodes; i++)
        if (visited[i])
            cout << i + 1 << ' ';
    cout << endl;
    cout << "--------------------------------------------------------------------" << endl;
}

//function for a* algorithm to count the distance between two nodes
double straightValue(double x1, double x2, double y1, double y2)
{
   return sqrt(pow((x1-x2),2) + pow((y2-y1),2));
}

void solution2()
{
    initialize();

    //store estimate of the remaining distance
    double estimate[countNodes];
    for (int i=0; i<countNodes; i++)
    {
        estimate[i] = straightValue(nodes[i].nodeX, nodes[destNode-1].nodeX, nodes[i].nodeY, nodes[destNode-1].nodeY);
    }
    
    //set a boolean array to flag if node has been visited
    bool visited[countNodes];
    for (int i=0; i<countNodes; i++)
        visited[i] = false;
    
    //set index array to identify the distance
    int index[countNodes];
    for (int i=0; i<countNodes; i++)
        index[i] = i;
    
    //mark source node as visited
    visited[sourceNode-1] = true;
    
    //for i=1 to n do
    double aStar[countNodes]; 
    for (int i=0; i<countNodes; i++)
    {
        d[i] = graphic[sourceNode-1][i]; //d[i] = L[source, i]
        aStar[i] = d[i] + estimate[i];
        sift_up(aStar, index, i); //inset d array and index array into a heap and sorted
        p[i] = sourceNode - 1; //p[i] = source
    }
    
    //repeat while destination is not visited
    int v = 0;
    int w = 0;
    int countNotSelected = countNodes;
    while (v != destNode - 1)
    {
        //v = the index of the minimum d[v] not yet selected
        v = index[0];
        //throw notifcation there is no path between the nodes
        if (d[v] == 999) 
        {
            cout << "No edge between nodes." << endl;
            return;
        }

        //mark v as visited
        visited[v] = true;
        
        //for each w hasn't been visited do
        if(v != destNode - 1)
        {
            aStar[0] = aStar[countNotSelected-1];
            index[0] = index[countNotSelected-1];
            sift_down(aStar, index, 0, countNotSelected);
            countNotSelected--;

            for (w=0; w<countNodes; w++)
            {
                if (visited[w] == false)
                {
                    if (d[w] > d[v] + graphic[v][w])
                    {
                        d[w] = d[v] + graphic[v][w];
                        int i = 0;
                        while (i < countNodes && index[i] != w) //find w in the index array
                            i++;
                        aStar[i] = d[v] + graphic[w][v] + estimate[w]; //change star array value as weel
                        sift_up(aStar, index, i);
                        p[w] = v;
                    }
                }
            }
        }
    }
    
    // get the path from the path array
    int shortestPath[countNodes];
    int k = 0;
    int j = destNode-1;
    while (j != sourceNode-1)
    {
        shortestPath[k] = j;
        j = p[j];
        k++;
    }
    shortestPath[k] = sourceNode - 1;

    cout << "The length of the shortest path from solution 2: " << d[destNode - 1]<< endl;
    cout << "The Path from solution 2: ";
    for (int i=k; i>0; i--)
        cout << shortestPath[i]+1 << "-->";
    cout << shortestPath[0]+1;
    cout << endl;
    cout << "The number of additional nodes in the solution tree for solution 2: " << endl;
    for (int i=0; i<=k; i++)
        visited[shortestPath[i]] = false;
    for (int i=0; i<countNodes; i++)
        if (visited[i])
            cout << i + 1 << ' ';
    cout << endl;
    cout << "--------------------------------------------------------------------" << endl;
}

void solution3()
{
    initialize();

    double d2[MAXSIZE] = {0};
    double p2[MAXSIZE] = {0};
    //set two boolean arrays to flag if nodes have been visited
    bool visited[countNodes];
    for (int i=0; i<countNodes; i++) //initialize
        visited[i] = false;

    bool visited2[countNodes];
    for (int i=0; i<countNodes; i++) //initialize
        visited2[i] = false;
    
    //set two index arrays to identify the distance
    int index[countNodes];
    for (int i=0; i<countNodes; i++)
        index[i] = i;

    int index2[countNodes];
    for (int i=0; i<countNodes; i++)
        index2[i] = i;
    
    //marked source and destination node to be visited
    visited[sourceNode-1] = true;
    visited2[destNode-1] = true;

    //for i=1 to n do
    double copy_d[countNodes]; //make two copy d arrays to do heap sort to prevent data change in d array
    double copy_d2[countNodes];

    for (int i=0; i<countNodes; i++)
    {
        d[i] = graphic[sourceNode-1][i]; //d[i] = L[source, i]
        d2[i] = graphic[destNode-1][i];
        copy_d[i] = graphic[sourceNode-1][i];
        copy_d2[i] = graphic[destNode-1][i];
        sift_up(copy_d, index, i); //inset d array and index array into a heap and sorted
        sift_up(copy_d2, index2, i); //inset d2 array and index2 array into a heap and sorted
        p[i] = sourceNode - 1; //p[i] = source
        p2[i] = destNode - 1; //p[i] = destination
    }
    
    //repeat while v not visited in the other flag array is not visited
    int v = 0;
    int v2 = 0;
    int w = 0;
    int stopNode = 0;
    int countNotSelected = countNodes;
    int countNotSelected2 = countNodes;
    while (visited[v2] == false && visited2[v] == false)
    {
        //v = the index of the minimum d[v] not yet selected
        v = index[0];
        v2 = index2[0];
        //throw notifcation there is no path between the nodes
        if (d[v] == 999 || d2[v2] == 999) 
        {
            cout << "No edge between nodes." << endl;
            return;
        }
        //mark v as visited
        visited[v] = true;
        visited2[v2] = true;
        
        //for each w not visited do
        if(visited[v2] == false && visited2[v] == false)
        {
            copy_d[0] = copy_d[countNotSelected-1];
            copy_d2[0] = copy_d2[countNotSelected2-1];
            index[0] = index[countNotSelected-1];
            index2[0] = index2[countNotSelected2-1];
            sift_down(copy_d, index, 0, countNotSelected);
            sift_down(copy_d2, index2, 0, countNotSelected2);
            countNotSelected--;
            countNotSelected2--;
            
            for (w=0; w<countNodes; w++)
            {
                if (visited[w] == false)
                {
                    if (d[w] > d[v] + graphic[v][w])
                    {
                        d[w] = d[v] + graphic[v][w];
                        int i = 0;
                        while (i < countNodes && index[i] != w) //find the w in the index array
                            i++;
                        copy_d[i] = d[v] + graphic[w][v]; //change copy array as well
                        sift_up(copy_d, index, i);
                        p[w] = v;
                    }
                }
                if (visited2[w] == false)
                {
                    if (d2[w] > d2[v2] + graphic[v2][w])
                    {
                        d2[w] = d2[v2] + graphic[v2][w];
                        int i = 0;
                        while (i < countNodes && index2[i] != w) //find the w in the index array
                            i++;
                        copy_d2[i] = d2[v2] + graphic[w][v2]; //change copy array as well
                        sift_up(copy_d2, index2, i);
                        p2[w] = v2;
                    }
                }
            }
        }
        else
            stopNode = (visited2[v] == true ? v : v2);
    }

    // get the path from the path array
    int shortestPath[countNodes];
    int k = 0;
    int j = stopNode;
    while (j != sourceNode-1)
    {
        visited[j] = false;
        shortestPath[k] = j;
        j = p[j];
        k++;
    }
    shortestPath[k] = sourceNode - 1;

    cout << "The length of the shortest path from solution 3: " << d[stopNode] + d2[stopNode] << endl;
    cout << "The Path from solution 3: ";
    for (int i=k; i>0; i--)
        cout << shortestPath[i]+1 << "-->";
    j = stopNode;
    while (j != destNode-1)
    {
        visited2[j] = false;
        cout << j+1 << "-->";
        j = p2[j];
    }
    visited[sourceNode-1] = false;
    visited2[destNode-1] = false; 
    cout << destNode;
    cout << endl;
    cout << "The number of additional nodes in the solution tree for solution 3: " << endl;
    for(int i=0; i<countNodes; i++)
        if(visited[i] == true || visited2[i] == true)
            cout << i+1 << ' ';
    cout << endl;
    cout << endl;
}

int main()
{
    readFile();
    solution1();
    solution2();
    solution3();
    delete []trips; 
    return 0;
}


