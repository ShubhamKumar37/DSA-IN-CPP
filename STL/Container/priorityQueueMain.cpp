#include<IOSTREAM>
#include<QUEUE>

using namespace std;

int main()
{
    // By default it is max_heap
    priority_queue<int> pq1;

    // For minhead we will use this
    priority_queue<int, vector<int>, greater<int>> pq2;

    pq1.push(23);
    pq1.push(34);
    pq1.push(54);
    pq1.push(23);
    pq1.push(12);
    pq1.push(273);


    cout << pq1.top() << endl;
    pq1.pop();
    cout << pq1.top() << endl;


    return 0;
}