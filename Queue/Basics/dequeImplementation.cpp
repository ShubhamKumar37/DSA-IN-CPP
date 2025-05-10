#include <iostream>

using namespace std; 

class Deque
{
    public: 
    int *arr;
    int size;
    int front;
    int rear;

    Deque(int size)
    {
        this -> arr = new int[size];
        this -> front = -1;
        this -> rear = -1;
        this -> size = size;
    }

    bool isEmpty();
    int popFront();
    int popBack();
    void pushFront(int);
    void pushBack(int val);
    void print();
};

bool Deque :: isEmpty()
{
    return front == -1 || front > rear;
}

int Deque :: popFront()
{
    if(isEmpty()) cout << "Deque is empty" << endl;
    if(rear == 0) 
    {
        int val = arr[rear];
        front = -1;
        rear = -1;
        return val;
    }
    return arr[front++];
}

int Deque :: popBack()
{
    if(isEmpty()) cout << "Deque is empty" << endl;
    if(rear == 0) 
    {
        int val = arr[rear];
        front = -1;
        rear = -1;
        return val;
    }
    return arr[rear--];
}

void Deque :: pushFront(int val)
{
    if(front == 0)
    {
        cout << "There is no space in front to push the element" << endl;
        return ;
    }

    arr[--front] = val;
}

void Deque :: pushBack(int val)
{
    if(rear + 1 == size)
    {
        cout << "Dequeu overflowed" << endl;
        return;
    }

    if(front == -1)
    {
        front = 0;
        rear = 0;
        arr[rear] = val;
    }
    else arr[++rear] = val;
}

void Deque :: print()
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    Deque dq(4);

    dq.pushBack(12);
    dq.print();
    
    dq.popFront();
    dq.print();
    dq.popFront();
    dq.print();
    // dq.pushBack(13);
    // dq.print();
    // dq.pushBack(14);
    // dq.print();
    // dq.pushBack(24);
    // dq.print();
    // dq.pushBack(54);
    // dq.print();
    
    // dq.pushFront(10);
    // dq.print();
    // dq.popFront();
    // dq.print();
    // dq.pushFront(10);
    // dq.print();


    return 0;
}