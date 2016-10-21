/*
Author: Libo Jia
Student No: 4781909
Date: 2015/09/05
Desc: This file is to simulation airplane counter server 
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

struct ServerClass{
	double heap[21];		//event time(service finish time or customer arrival time)
	int id[21];			//event identification
	int busyNum;			//busy server number
	int totalServerNum;		//number of total server
	double totalRealServiceTime;	//total real service time(exclude waiting time)
	int totalCustomers;		//total customers
	double lastTime; 	//Time last service request is completed
	double time;		//current time
	double arrivalTime;	//customer arrival time
	double serviceTime;	//customer service time
	double nextServiceTime; //next customer service time
	bool readComplete;	//file reading complete identification
	int filePos; 	//hold filestream position
	double idleStartTime[21];	//server idle start time 
	double totalIdleTime[21];	//server total idle time
	bool typeDone;	//flag when a server type is done
	double queue[500];	//queue for storing service_time
	double arrivalTimeQueue[500];	//queque for storing time when adding customers to queue
	double totalQueueTime;	//total time for customer waiting being serviced
	bool queueIsChange; //flag when queue length changes
	int front;		//front indication of queue	
	int rear;		//rear ubducatuib of queue
	int queueSize;	//size of queue
	int maxQueueSize;	//max length of queue
	double queueStartTime;	//time when first elements in queue
	double preTime;	//previous queue changed time
	int preSize;	//previous queue size
	double totalQueueLength; //total queue length
};

//check queue full status
bool queueIsEmpty(const ServerClass& serverClass)
{
	return ((serverClass.rear==serverClass.front)?true:false);
}

//check queue empty status
bool queueIsFull(const ServerClass& serverClass)
{
	int index = (serverClass.front + 1)%500;
	return ((index==serverClass.rear)?true:false);
}

//put elements in queue
bool enqueue(ServerClass& serverClass)
{
	if(queueIsFull(serverClass))
		return false;
	
	//enqueue
	serverClass.queue[serverClass.front] = serverClass.serviceTime;
	serverClass.arrivalTimeQueue[serverClass.front] = serverClass.time;
	serverClass.front = (serverClass.front + 1)%500;
	
	serverClass.queueIsChange = true;
	serverClass.queueSize = abs(serverClass.front - serverClass.rear);
	//when queue size change, update max size of queue
	if(serverClass.maxQueueSize < serverClass.queueSize)
		serverClass.maxQueueSize = serverClass.queueSize;	
		
	return true;
}

//return elements from queue
double dequeue(ServerClass& serverClass, double time)
{	
		double result = serverClass.queue[serverClass.rear];
		serverClass.totalQueueTime += time - serverClass.arrivalTimeQueue[serverClass.rear];
		serverClass.rear = (serverClass.rear + 1)%500;
		serverClass.queueIsChange = true;	
		serverClass.queueSize--;
		
		return result;
}

//swap two int elements
void swap(int& idX, int& idY)
{
	int tmpId = idX;
	idX = idY;
	idY= tmpId;
}

//swap two double elements
void swap(double& heapX, double& heapY)
{
	double tmpHeap = heapX;
	heapX = heapY;
	heapY = tmpHeap;
}

//reheap downside
void shiftDown(ServerClass& serverClass)
{
	int i =0;
	bool down = true;
	while(i <= serverClass.busyNum && down)
	{
		if(2*i+2 <= serverClass.busyNum)	//has two children
		{
			if(serverClass.heap[2*i+1] < serverClass.heap[2*i+2])	//left child is smaller
			{
				if(serverClass.heap[2*i+1] < serverClass.heap[i])	//swap
				{
					swap(serverClass.heap[2*i+1], serverClass.heap[i]);
					swap(serverClass.id[2*i+1], serverClass.id[i]);
					i = 2*i +1;	//next level
				}
				else
					down = false;
			}
			else	//right child is smaller
			{
				if(serverClass.heap[2*i+2] < serverClass.heap[i])	//swap
				{
					swap(serverClass.heap[2*i+2], serverClass.heap[i]);
					swap(serverClass.id[2*i+2], serverClass.id[i]);
					i = 2*i +2;	//next level
				}
				else
					down = false;
			}
		}
		else if(2*i+1 <= serverClass.busyNum)	//only one left child
		{
			if(serverClass.heap[2*i+1] < serverClass.heap[i])	//swap
			{
				swap(serverClass.heap[2*i+1], serverClass.heap[i]);
				swap(serverClass.id[2*i+1], serverClass.id[i]);	
				i = 2*i +1;	//next level
			}
			else
				down = false;
		}
		else	//no child
			down = false;
	}
}

//reheap upside
void shiftUp(ServerClass& serverClass)
{
	int i = serverClass.busyNum;
	while(i>0 && (serverClass.heap[i]<serverClass.heap[(i-1)/2]))
	{
		swap(serverClass.heap[(i-1)/2], serverClass.heap[i]);
		swap(serverClass.id[(i-1)/2], serverClass.id[i]);
		i = (i-1)/2;	//next level
	}
}

//struct elements initialization
void initial(ServerClass& serverClass, int totalServerNum)
{
	serverClass.busyNum = 0;
	serverClass.totalServerNum = totalServerNum;
	serverClass.totalRealServiceTime = 0;
	serverClass.totalCustomers = 0;
	serverClass.time = 0;
	serverClass.readComplete = false;
	
	for (int i=0; i<=totalServerNum; i++)
	{
		serverClass.id[i] = i;
		serverClass.idleStartTime[i] = 0;
		serverClass.totalIdleTime[i] = 0;
	}	
	
	serverClass.front = 0;
	serverClass.rear = 0;
	serverClass.maxQueueSize = 0;
	serverClass.totalQueueTime = 0;
	serverClass.preTime = 0;
	serverClass.preSize = 0;
	serverClass.totalQueueLength = 0;
	
	serverClass.typeDone = false;
}

//read item from file
void readItem(ServerClass& serverClass, ifstream& fin, int type)
{
	char ch;
	int classType;
	bool isFound = false;
	
	//relacate file stream to correct position
	fin.clear();	//clear file stream err if any
	fin.seekg(serverClass.filePos ,ios::beg);
	
	//read next item
	while(fin >> serverClass.arrivalTime >> ch 
			>> serverClass.nextServiceTime >> ch >> classType)
	{
		if(classType == type && serverClass.arrivalTime != 0)
		{
			isFound = true;
			serverClass.filePos = fin.tellg();	//save current file stream position
			break;		
		}
	}
	
	//if no new item found, set flag off
	if(!isFound)
	{
		serverClass.arrivalTime = 99999999;
		serverClass.readComplete = true;	
	}
}

//handle seperate simulation customer arrival events
void customerArrivalEvent(ServerClass& serverClass, ifstream& fin, int classType)
{
	serverClass.time = serverClass.heap[0];	//get current time
	readItem(serverClass, fin, classType);	//read next customer arrival infomation
	serverClass.heap[0] = serverClass.arrivalTime;	//set new arrival time	
	shiftDown(serverClass);	//reheap
	
	if(serverClass.busyNum < serverClass.totalServerNum)
	{
		serverClass.busyNum++;
		int index = serverClass.id[serverClass.busyNum];	//get server number
		serverClass.totalIdleTime[index] += serverClass.time - serverClass.idleStartTime[index];	//calc idle time
		serverClass.heap[serverClass.busyNum] = serverClass.time + serverClass.serviceTime;		//update time when this service finishes
		serverClass.totalRealServiceTime += serverClass.serviceTime;	//update total service time	
		shiftUp(serverClass);	//reheap
	}
	else
		enqueue(serverClass);
	
	serverClass.serviceTime = serverClass.nextServiceTime;			
}

//handle mixed simulation customer arrival events
void customerArrivalMixEvent(ServerClass& serverClass, ServerClass& helpClass, ifstream& fin, int classType)
{
	serverClass.time = serverClass.heap[0];
	readItem(serverClass, fin, classType);
	serverClass.heap[0] = serverClass.arrivalTime;
	shiftDown(serverClass);
	
	if(serverClass.busyNum < serverClass.totalServerNum)
	{
		serverClass.busyNum++;
		int index = serverClass.id[serverClass.busyNum];
		serverClass.totalIdleTime[index] += serverClass.time - serverClass.idleStartTime[index];
		serverClass.heap[serverClass.busyNum] = serverClass.time + serverClass.serviceTime;
		serverClass.totalRealServiceTime += serverClass.serviceTime;	
		shiftUp(serverClass);
	}
	else
	{
		if(helpClass.busyNum < helpClass.totalServerNum)	//if the other server type have server available, put this task on that server
		{
			helpClass.busyNum++;
			helpClass.heap[helpClass.busyNum] = serverClass.time + serverClass.serviceTime;
			helpClass.totalRealServiceTime += serverClass.serviceTime;
			
			int index = helpClass.id[helpClass.busyNum];	//get server number		
			helpClass.totalIdleTime[index] += serverClass.time - helpClass.idleStartTime[index];	//calc idle time
			shiftUp(helpClass);		//reheap
		}
		else
			enqueue(serverClass);
	}
	
	serverClass.serviceTime = serverClass.nextServiceTime;			
}

//handle seperate simulation server finish events
void serverFinishEvent(ServerClass& serverClass)
{	
	serverClass.totalCustomers++;	//update number of customer servered
	serverClass.time = serverClass.heap[0];	//get current time
	
	if(queueIsEmpty(serverClass))
	{	
		//get time when last service request
		if(serverClass.readComplete && serverClass.busyNum == 1)
			serverClass.lastTime = serverClass.heap[0];
			
		int index = serverClass.id[0];	//get server number
		serverClass.idleStartTime[index] = serverClass.time;	//update server idle start time
		
		//swap
		swap(serverClass.id[0], serverClass.id[serverClass.busyNum]);
		swap(serverClass.heap[0], serverClass.heap[serverClass.busyNum]);
		
		//update busy servers number
		serverClass.busyNum--;
	}
	else
	{
		double dequeueTime = dequeue(serverClass, serverClass.time); 
		serverClass.heap[0] = serverClass.time + dequeueTime;
		serverClass.totalRealServiceTime += dequeueTime;
	}
	
	shiftDown(serverClass);
}

//handle mixed simulation server finish events
void serverFinishMixEvent(ServerClass& serverClass, ServerClass& calledClass)
{	
	serverClass.totalCustomers++;	//update number of customer servered
	serverClass.time = serverClass.heap[0];	//get current time
	
	if(queueIsEmpty(serverClass))
	{	
		//get time when last service request
		if(serverClass.readComplete && serverClass.busyNum == 1)
			serverClass.lastTime = serverClass.heap[0];
			
		//get server number
		int index = serverClass.id[0];

		//update server idle start time
		serverClass.idleStartTime[index] = serverClass.time;
		
		//swap
		swap(serverClass.id[0], serverClass.id[serverClass.busyNum]);
		swap(serverClass.heap[0], serverClass.heap[serverClass.busyNum]);
		
		if(!queueIsEmpty(calledClass))
		{
			double helpServiceTime = dequeue(calledClass, serverClass.time);
			serverClass.heap[serverClass.busyNum] = serverClass.time +  helpServiceTime;
			serverClass.totalRealServiceTime += helpServiceTime;
		}
		else
			serverClass.busyNum--;
	}
	else
	{
		double dequeueTime = dequeue(serverClass, serverClass.time); 
		serverClass.heap[0] = serverClass.time + dequeueTime;
		serverClass.totalRealServiceTime += dequeueTime;
	}
	
	shiftDown(serverClass);
}

//update total queue length
void updateTotalQueueLength(ServerClass& serverClass)
{
	//calculate total queue length(by area)
	serverClass.totalQueueLength += (serverClass.time - serverClass.preTime)* serverClass.preSize;
	serverClass.preTime = serverClass.time;
	serverClass.preSize = serverClass.queueSize;
}

//display simulation results
void showResults(ServerClass& firstClass, ServerClass& commonClass, int maxOverallQueueSize)
{
	//according to final finish time update each server idle time
	double finalTime = ((firstClass.lastTime>commonClass.lastTime)?firstClass.lastTime:commonClass.lastTime);
	for(int i=1;i<=firstClass.totalServerNum;i++)
		firstClass.totalIdleTime[i] += finalTime - firstClass.idleStartTime[i];
	for(int i=1;i<=commonClass.totalServerNum;i++)
		commonClass.totalIdleTime[i] += finalTime - commonClass.idleStartTime[i];		
	
	cout << "\n\n" << "########################### Simulation Results ############################\n\n";
	cout << "Number of People served in FirstClass servers are: " << firstClass.totalCustomers << endl;
	cout << "Number of People served in TouristClass servers are: " << commonClass.totalCustomers << endl;
	cout << "Number of Poeple served by all servers are: " << firstClass.totalCustomers + commonClass.totalCustomers << endl;
	cout << "---------------------------------------------------------------------------\n";
	cout << "Time last FirstClass service request is complete: " << firstClass.lastTime << endl;
	cout << "Time last TouristClass service request is complete: " << commonClass.lastTime << endl;
	cout << "Time last service request is complete: " << finalTime << endl;
	cout << "---------------------------------------------------------------------------\n";
	cout << "Average total service time for FirstClass is: " << (firstClass.totalRealServiceTime + firstClass.totalQueueTime)/firstClass.totalCustomers << endl;
	cout << "Average total service time for TouristClass is: " << (commonClass.totalRealServiceTime + commonClass.totalQueueTime)/commonClass.totalCustomers << endl;
	cout << "Average total service time is: " << ((firstClass.totalRealServiceTime + firstClass.totalQueueTime)+(commonClass.totalRealServiceTime + commonClass.totalQueueTime))/(firstClass.totalCustomers + commonClass.totalCustomers) << endl;
	cout << "---------------------------------------------------------------------------\n";
	cout << "Average total time in queue for FirstClass is: " << firstClass.totalQueueTime/firstClass.totalCustomers << endl;
	cout << "Average total time in queue for TourisClass is: " << commonClass.totalQueueTime/commonClass.totalCustomers << endl;
	cout << "Average total time in queue is: " << (firstClass.totalQueueTime + commonClass.totalQueueTime)/(firstClass.totalCustomers + commonClass.totalCustomers) << endl;
	cout << "---------------------------------------------------------------------------\n";
	cout << "Average length of queue for FirstClass is: " << firstClass.totalQueueLength/finalTime << endl;
	cout << "Average length of queue for TouristClass is: " << commonClass.totalQueueLength/finalTime << endl;
	cout << "Average length of queue is: " << (firstClass.totalQueueLength + commonClass.totalQueueLength)/(2*finalTime) << endl;
	cout << "---------------------------------------------------------------------------\n";
	cout << "Max length of FirstClass queue is: " << firstClass.maxQueueSize << endl;
	cout << "Max length of TouristClass queue is: " << commonClass.maxQueueSize << endl;
	cout << "Max length of overall queue is: " << maxOverallQueueSize << endl;
	cout << "---------------------------------------------------------------------------\n";
	for(int i =1; i<= firstClass.totalServerNum; i++)
		cout << "Total idle time for FirstClss server " << i << " is " << firstClass.totalIdleTime[i] << endl;
	for(int i =1; i<= commonClass.totalServerNum; i++)
		cout << "Total idle time for TouristClss server " << i << " is " << commonClass.totalIdleTime[i] << endl;
	cout << "\n########################### Enf Of Simulation #############################\n\n\n";
}

int main()
{
	ServerClass firstClass, commonClass;
	int maxOverallQueueSize = 0;	//initial max overall queue size
	
	ifstream fin("test.txt");
	// ifstream fin("ass2data.txt");
	if(!fin)
	{
		cout << "Cannot open file ass2data.txt.\n";
		return -1;
	}
	
	//get server configeration
	int firstNum, commonNum;
	char ch;
	fin >> firstNum >> ch >> commonNum;
	
	//get file stream position for each server type
	int filePos = fin.tellg();
	firstClass.filePos = filePos;
	commonClass.filePos = filePos;

	/*************************************************************
	 *round1 first class and common class seperately simulation
	 ************************************************************/
	//initialization both server type data members
	initial(firstClass, firstNum);
	initial(commonClass, commonNum);
	
	//read one item from file in each type
	readItem(firstClass, fin, 1);
	readItem(commonClass, fin, 0);

	//put first customer's arrival time in heap
	firstClass.heap[0] = firstClass.arrivalTime;
	firstClass.serviceTime = firstClass.nextServiceTime;
	commonClass.heap[0] = commonClass.arrivalTime;
	commonClass.serviceTime = commonClass.nextServiceTime;
	
	while(!(firstClass.typeDone && commonClass.typeDone))
	{	
		firstClass.queueIsChange = false;
		commonClass.queueIsChange = false;
		
		//compare two event type time stamp to deal with the coming event 
		if((firstClass.heap[0] <= commonClass.heap[0]) && (!firstClass.typeDone))	//firstClass type event
		{	
			if(firstClass.id[0] == 0) //Customer arrives event
				customerArrivalEvent(firstClass, fin, 1);
			else	//server finish event
				serverFinishEvent(firstClass);
				
			//endloop condition			
			if(firstClass.id[0] == 0 && firstClass.readComplete)
				firstClass.typeDone = true;
		}
		else if((firstClass.heap[0] > commonClass.heap[0]) && (!commonClass.typeDone))//commonClass type event
		{
			if(commonClass.id[0] == 0) //Customer arrives event
				customerArrivalEvent(commonClass, fin, 0);
			else	//server finish event
				serverFinishEvent(commonClass);
			
			//endloop condition			
			if(commonClass.id[0] == 0 && commonClass.readComplete)
				commonClass.typeDone = true;
		}
		
		if(firstClass.queueIsChange)	
			updateTotalQueueLength(firstClass);
		else if(commonClass.queueIsChange)
			updateTotalQueueLength(commonClass);
		
		//upate overall max queue size
		if(maxOverallQueueSize < (firstClass.maxQueueSize + commonClass.maxQueueSize))
			maxOverallQueueSize = firstClass.maxQueueSize + commonClass.maxQueueSize;
	}
	//display simulation results
	cout << "The First Round of Simulation: First Class and Tourist Class Seperately";
	showResults(firstClass, commonClass, maxOverallQueueSize);
	
	/*************************************************************
	 *round2 first class and common class mixed simulation
	 ************************************************************/
	maxOverallQueueSize = 0;	//reset max overall queue size
	
	//initialization both server type data members
	initial(firstClass, firstNum);
	initial(commonClass, commonNum);
	
	//get file stream position for each server type
	firstClass.filePos = filePos;
	commonClass.filePos = filePos;
	
	//read one item from file in perticular type
	readItem(firstClass, fin, 1);
	readItem(commonClass, fin, 0);

	//put first customer's arrival time in heap
	firstClass.heap[0] = firstClass.arrivalTime;
	firstClass.serviceTime = firstClass.nextServiceTime;
	commonClass.heap[0] = commonClass.arrivalTime;
	commonClass.serviceTime = commonClass.nextServiceTime;
	
	while(!(firstClass.typeDone && commonClass.typeDone))
	{	
		firstClass.queueIsChange = false;
		commonClass.queueIsChange = false;
		
		//compare two event type time stamp to deal with the coming event 
		if((firstClass.heap[0] <= commonClass.heap[0]) && (!firstClass.typeDone))	//firstClass type event
		{	
			if(firstClass.id[0] == 0) //Customer arrives event
				customerArrivalEvent(firstClass, fin, 1);
			else	//server finish event
				serverFinishMixEvent(firstClass, commonClass);
			
			//endloop condition			
			if(firstClass.id[0] == 0 && firstClass.readComplete)
				firstClass.typeDone = true;
		}
		else if((firstClass.heap[0] > commonClass.heap[0]) && (!commonClass.typeDone))	//commonClass type event
		{
			if(commonClass.id[0] == 0) //Customer arrives event
				customerArrivalMixEvent(commonClass, firstClass, fin, 0);
			else	//server finish event
				serverFinishEvent(commonClass);
			
			//endloop condition			
			if(commonClass.id[0] == 0 && commonClass.readComplete)
				commonClass.typeDone = true;
		}
		
		if(firstClass.queueIsChange)
			updateTotalQueueLength(firstClass);
		else if(commonClass.queueIsChange)
			updateTotalQueueLength(commonClass);
		
		//upate overall max queue size
		if(maxOverallQueueSize < (firstClass.maxQueueSize + commonClass.maxQueueSize))
			maxOverallQueueSize = firstClass.maxQueueSize + commonClass.maxQueueSize;
	}
	//display simulation results
	cout << "The Second Round of Simulation: First Class and Tourist Class Mixed";
	showResults(firstClass, commonClass, maxOverallQueueSize);
	
	fin.close();
	return 0;
}
