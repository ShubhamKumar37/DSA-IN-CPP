#include <iostream>
using namespace std;

class Stack
{
private:
    int top;
    int size;
    int *arr;

public:
    Stack(int capacity)
    {
        top = -1;
        size = capacity;
        this->arr = new int[size];
    }

    void push(int value)
    {
        if (top == size - 1)
            cout << "Stack Overflow" << endl;

        else
            arr[++top] = value;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow";
            return -1;
        }
        return arr[top--];
    }

    void print()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{
    Stack myStack(5);
    myStack.push(1);
    myStack.push(2);
    myStack.push(4);
    myStack.push(6);
    myStack.push(6);
    myStack.push(6);
    myStack.push(6);
    myStack.pop();
    myStack.print();
    return 0;
}