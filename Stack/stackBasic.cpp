#include <iostream>

using namespace std;

class Stack
{
public:
    int *arr;
    int ind;
    int size;

    Stack(int size)
    {
        this->arr = new int[size];
        this->ind = -1;
        this->size = size;
    }

    void push(int ele)
    {
        if (ind == size - 1)
        {
            cout << "Stack is full right now" << endl;
            return;
        }

        ind++;
        arr[ind] = ele;
    }
    int pop()
    {
        if (ind == -1)
        {
            cout << "Stack is empty" << endl;
            return -1;
        }

        int ele = arr[ind];
        arr[ind] = -1;
        ind--;
        return ele;
    }

    int top()
    {
        if (ind == -1)
        {
            cout << "Stack is already empty" << endl;
            return -1;
        }
        return arr[ind];
    }

    int getSize() { return ind + 1; }
    bool empty() { return ind == -1; }
    bool isFull() { return ind == size + 1; }
};

// This is wrong as the stack have memory allocated through pointer so the changes will be original but the only copy is the variable not the reference
// void printStack(Stack s)
// {
//     if(s.empty()) return ;

//     cout << s.top() << " ";
//     s.pop();
//     printStack(s);
// }

int main()
{
    // Stack s = Stack(5);
    Stack s(5);

    s.push(3);
    cout << endl;
    s.push(32);
    cout << endl;
    s.push(13);
    cout << endl;
    s.push(32);
    cout << endl;

    cout << s.top() << endl;
    // s.pop();
    // s.pop();
    // s.pop();
    // cout << s.top() << endl;
    cout << s.getSize() << endl;
    // cout << s.empty() << endl;
    // cout << s.isFull() << endl;

    return 0;
}