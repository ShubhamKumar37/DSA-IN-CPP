#include <iostream>

using namespace std;

class Circular_Queue
{
    public: 
    int size;
    int front;
    int rear;
    int *arr;

    Circular_Queue(int size)
    {
        this -> arr = new int[size];
        this -> size = size;
        this -> front = -1;
        this -> rear = -1;
    }

    int pop();
    int getFront();
    bool isEmpty();
    bool isFull();
    bool isSameIndex();
    void push(int);
    void print();

};


int main()
{
    Circular_Queue cq(4);

    cq.push(5); cq.print();
    cq.push(8); cq.print();
    cq.push(1); cq.print();
    cq.push(10); cq.print();
    cq.push(100); cq.print();
    cq.pop(); cq.print();
    cq.push(100); cq.print();
    cq.pop(); cq.print();
    cq.pop(); cq.print();
    cq.pop(); cq.print();
    cq.push(100); cq.print();
    cq.pop(); cq.print();
    cout << cq.front << " - " << cq.rear << endl;
    cq.pop(); cq.print();
    cout << cq.front << " - " << cq.rear << endl;
    cq.pop(); cq.print();
    cout << cq.getFront() << endl;
    
    return 0;
}


bool Circular_Queue :: isEmpty()
{
    return front == -1 || rear == -1;
}

bool Circular_Queue :: isSameIndex()
{
    if(front + 1 == size) return rear == 0;
    else return front + 1 == rear;
}

int Circular_Queue :: pop()
{
    if(isEmpty()) 
    {
        cout << "Circular queue underflow" << endl; 
        return -1;
    }

    int val = arr[front];
    if(rear == 0 && front == 0){
        rear = -1;
        front = -1;
        arr[0] = -1;
    }
    else if(isSameIndex())
    {
        arr[front] = -1;
        arr[0] = arr[rear];
        arr[rear] = -1;
        front = 0;
        rear = 0;
    }
    else if(front + 1 < size)
    {
        arr[front] = -1;
        ++front;
    }
    else{
        arr[front] = -1;
        front = 0;
    }

    return val;
}

int Circular_Queue :: getFront()
{
    if(isEmpty()) 
    {
        cout << "Circular queue is already empty" << endl;
        return -1;
    }

    return arr[front];
}

bool Circular_Queue :: isFull()
{
    if(rear + 1 == size && front == 0) return true;
    else if(rear + 1 == front) return true;
    return false;
}

void Circular_Queue :: push(int val)
{
    if(isFull())
    {
        cout << "Circular queue overflow" << endl;
        return ;
    }

    if(front == -1)
    {
        arr[++front] = val;
        rear = 0;
    }
    else if(rear + 1 == size)
    {
        rear = 0;
        arr[rear] = val;
    }
    else arr[++rear] = val;
}

void Circular_Queue :: print()
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}