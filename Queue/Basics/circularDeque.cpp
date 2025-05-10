#include <iostream>

using namespace std;

class Circular_Deque
{
public:
    int size;
    int *arr;
    int front;
    int back;

    Circular_Deque(int size)
    {
        this->arr = new int[size];
        this->size = size;
        this->front = -1;
        this->back = -1;
    }

    int popFront();
    int popBack();
    void pushFront(int);
    void pushBack(int);
    bool isEmpty();
    bool isFull();
    int getSize();

    void print()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int
main()
{
    Circular_Deque cd(4);

    cd.pushBack(12); cd.print();
    cd.pushFront(25); cd.print();
    cd.pushFront(30); cd.print();
    cd.pushFront(3); cd.print();
    cd.pushFront(9); cd.print();
    cout << cd.front << " - " << cd.back << endl;
    cd.popBack(); cd.print();
    cd.popBack(); cd.print();
    cd.popBack(); cd.print();
    cd.popBack(); cd.print();
    cd.popBack(); cd.print();
    cout << cd.getSize() << endl;
    cout << cd.front << " - " << cd.back << endl;
    cd.pushFront(32); cd.print();
    cout << cd.front << " - " << cd.back << endl;
    cd.pushFront(67); cd.print();
    cd.pushFront(11); cd.print();
    cd.pushFront(90); cd.print();
    cout << cd.front << " - " << cd.back << endl;
    cout << cd.getSize() << endl;
    cd.popFront(); cd.print();
    cout << cd.front << " - " << cd.back << endl;
    cout << cd.getSize() << endl;
    cd.pushFront(100); cd.print();
    cout << cd.getSize() << endl;

    return 0;
}

bool Circular_Deque ::isFull()
{
    if (front == 0 && back == size - 1)
        return true;
    if (back + 1 == front)
        return true;
    return false;
}

void Circular_Deque ::pushFront(int val)
{
    if (isFull())
    {
        cout << "Circular deque overflow" << endl;
        return;
    }

    if (front == -1 && back == -1)
    {
        front = 0;
        back = 0;
        arr[front] = val;
    }
    else if (front == 0 && back != size - 1)
    {
        front = size - 1;
        arr[front] = val;
    }
    else
        arr[--front] = val;
}

void Circular_Deque ::pushBack(int val)
{
    if (isFull())
    {
        cout << "Circular deque overflow" << endl;
        return;
    }

    if (front == -1)
    {
        front = 0;
        back = 0;
        arr[back] = val;
    }
    else if (back == size - 1 && front != 0)
    {
        back = 0;
        arr[back] = val;
    }
    else
        arr[++back] = val;
}

int Circular_Deque ::popBack()
{
    if (isEmpty())
    {
        cout << "Circular deque underflow" << endl;
        return -1;
    }
    int val = arr[back];

    if (front == back)
    {
        arr[front] = -1;
        arr[back] = -1;
        front = -1;
        back = -1;
    }
    else if (back == 0 && front == size - 1)
    {
        arr[0] = arr[front];
        arr[front] = -1;
    }
    else if (back == 0 && front < size - 1)
    {
        arr[back] = -1;
        back = size - 1;
    }
    else
        arr[back--] = -1;

    return val;
}

int Circular_Deque ::popFront()
{
    if (isEmpty())
    {
        cout << "Circular deque underflow" << endl;
        return -1;
    }

    int val = arr[front];
    if (front == back)
    {
        arr[front] = -1;
        arr[back] = -1;
        front = -1;
        back = -1;
        cout << "here1" << endl;
    }
    else if (front == size - 1 && back == 0)
    {
        cout << "here2" << endl;
        arr[front] = -1;
        front = 0;
        back = 0;
    }
    else if (front == size - 1 && back > 0)
    {
        cout << "here3" << endl;
        arr[front] = -1;
        front = 0;
    }
    else arr[front++] = -1;

    return val;
}

bool Circular_Deque ::isEmpty()
{
    return front == -1 && back == -1;
}

int Circular_Deque ::getSize()
{
    if(front == -1) return 0;
    return size - front + back + 1;
}