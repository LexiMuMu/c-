/********************************************************************************
 * Filename: vectorProc.cpp
 * Name & Student No.: Yanhong Ben, 4845675
 * Lab No: 10
 * File Description: vector and template functions
 * Date Last Modified: 19/10/2015
 *********************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<class T>
bool same_elements(const vector<T> &, const vector<T> &);

template<class T>
void remove_duplicates(vector<T> &);

template<class T>
void push(T, vector<T> &);

int main()
{
    //test for int type
    int numV1, numV2;
    int temp1 = 0;
    int temp2 = 0;
    vector<int> v1;
    vector<int> v2;
    cout << "Input number of elements for integer v1: ";
    cin >> numV1;
    for (int i=0; i<numV1; i++)
    {
        cout << "Input data: ";
        cin >> temp1;
        push<int>(temp1, v1);
    }
    
    cout << "Input number of elements for integer v2: ";
    cin >> numV2;
    for (int i=0; i<numV2; i++)
    {
        cout << "Input data: ";
        cin >> temp2;
        push<int>(temp2, v2);
    }

    cout << endl;
    if (same_elements(v1, v2))
        cout << "v1 and v2 contain same elements." << endl;
    else
        cout << "v1 and v2 NOT contain same elements." << endl;
    
    cout << "After remove duplicates from v1, now it contains:";
    remove_duplicates(v1);
    vector<int>::iterator p1;
    for (p1=v1.begin(); p1!=v1.end(); p1++)
        cout<< *p1 << " ";
    cout << endl;
    
    cout << "After remove duplicates from v2, now it contains:";
    remove_duplicates(v2);
    vector<int>::iterator p2;
    for (p2=v2.begin(); p2!=v2.end(); p2++)
        cout<< *p2 << " ";
    cout << endl;

    //test for double type
    int numV3, numV4;
    double temp3 = 0;
    double temp4 = 0;
    vector<double> v3;
    vector<double> v4;
    cout << "Input number of elements for integer v1: ";
    cin >> numV3;
    for (int i=0; i<numV3; i++)
    {
        cout << "Input data: ";
        cin >> temp3;
        push<double>(temp3, v3);
    }
    
    cout << "Input number of elements for integer v2: ";
    cin >> numV4;
    for (int i=0; i<numV4; i++)
    {
        cout << "Input data: ";
        cin >> temp4;
        push<double>(temp4, v4);
    }

    cout << endl;
    if (same_elements(v3, v4))
        cout << "v1 and v2 contain same elements." << endl;
    else
        cout << "v1 and v2 NOT contain same elements." << endl;
    
    cout << "After remove duplicates from v1, now it contains:";
    remove_duplicates(v3);
    vector<double>::iterator p3;
    for (p3=v3.begin(); p3!=v3.end(); p3++)
        cout<< *p3 << " ";
    cout << endl;
    
    cout << "After remove duplicates from v2, now it contains:";
    remove_duplicates(v4);
    vector<double>::iterator p4;
    for (p4=v4.begin(); p4!=v4.end(); p4++)
        cout<< *p4 << " ";
    cout << endl;
    return  0;
}

template<class T>
bool same_elements(const vector<T> &val1, const vector<T> &val2)
{
    vector<T> temp1 = val1;
    vector<T> temp2 = val2;
    sort(temp1.begin(), temp1.end());
    sort(temp2.begin(), temp2.end());
    if (temp1.size() != temp2.size() )
    {
        return false;
    }
    return (temp1 == temp2);
};


template<class T>
void remove_duplicates(vector<T> &val)
{
    typename vector<T>::iterator p;
    for (p=val.begin(); p!=val.end(); p++)
        val.erase(remove(p+1, val.end(), *p), val.end());
}

template<class T>
void push(T value, vector<T> &v)
{
    v.push_back(value);
}
