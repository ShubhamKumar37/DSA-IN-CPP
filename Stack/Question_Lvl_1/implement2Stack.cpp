#include <IOSTREAM>

using namespace std;

class Stack
{
public:
    int size;
    int *arr;
    int ind1;
    int ind2;

    Stack(int size)
    {
        this->size = size;
        this->ind1 = -1;
        this->ind2 = size;
        this->arr = new int[size];
    }

    void push1(int ele)
    {
        if(isFull())
        {
            cout << "Stack is full" << endl;
            return ;
        }
        arr[++ind1] = ele;
    }
    
    void push2(int ele)
    {
        if(isFull())
        {
            cout << "Stack is full" << endl;
            return ;
        }
        arr[--ind2] = ele;
    }
    
    int pop1()
    {
        if(ind1 == -1)
        {
            cout << "Stack 1 is empty" << endl;
            return -1;
        }

        int ele = arr[ind1];
        arr[ind1--] = 0;
        return ele;
    }
    
    int pop2()
    {
        if (ind2 == size)
        {
            cout << "Stack 2 is empty" << endl;
            return -1;
        }

        int ele = arr[ind2];
        arr[ind2++] = 0;
        return ele;
    }
    
    bool empty()
    {
        return (ind1 == -1) && (ind2 == size);
    }
    
    bool isFull()
    {
        return abs(ind1 - ind2) == 1;
    }
};

int main()
{
    Stack s(4);

    return 0;
}