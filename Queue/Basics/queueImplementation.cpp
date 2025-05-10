#include <iostream>

using namespace std;

class Queue
{
    public: 
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size)
    {
        this -> size = size;
        arr = new int[size];
        this -> front = -1;
        this -> rear = -1;
    }

    int pop();
    int back();
    int getFront();
    bool empty();
    int getSize();
    void push(int val);
};

int Queue :: getSize()
{
    if(empty()) return 0;
    return rear - front + 1;
}

int Queue :: pop()
{
    if(rear == -1 && front == -1)
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    if(rear == 0 || front == rear)
    {
        int value = arr[front];
        front = -1;
        rear = -1;
        return value;
    }

    int value = arr[front++];
    return value;
}

int Queue :: back()
{
    if(rear == -1 && front == -1) 
    {
        cout << "Queue is already empty" << endl;
        return -1;
    }

    return arr[rear];
}

int Queue :: getFront() 
{
    if(rear == -1 && front == -1) 
    {
        cout << "Queue is already empty" << endl;
        return -1;
    }

    return arr[front];
}

bool Queue :: empty()
{
    return front == -1;
}

void Queue :: push(int val)
{
    if(rear + 1 == size)
    {
        cout << "Queue overflowed" << endl;
        return ;
    }

    if(front == -1)
    {
        rear = 0;
        front = 0;
        arr[front] = val;
        return ;
    }

    arr[++rear] = val;

}

int main()
{

    Queue q(4);

    q.push(2);
    q.push(3);
    q.push(4);
    q.push(4);
    q.pop();
    q.push(7);

    cout << q.getFront() << endl;
    cout << q.back() << endl;
    q.pop();
    q.push(10);
    q.pop();
    q.push(50);
    cout << q.back() << endl;
    cout << q.rear<< endl;
    q.pop();
    cout << q.empty() << endl;
    q.push(100);
    cout << q.getFront() << endl;
    cout << q.front << endl;

    return 0;
}