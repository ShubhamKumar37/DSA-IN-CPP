#include <iostream>

using namespace std;

class NStack
{
    int size, freeSpot, n;
    int *arr, *top, *next;
    public:

    NStack(int size, int n): size(size), n(n) 
    {
        this -> arr = new int[size];
        this -> top = new int[n];
        this -> next = new int[size];
        this -> freeSpot = 0;

        for(int i = 0; i < n; i++) top[i] = -1;
        for(int i = 0; i < size; i++) next[i] = i + 1;
        next[size - 1] = -1;
    }

    bool push(int val, int s)
    {
        if(freeSpot == -1) 
        {
            cout << "Stack overflowed" << endl;
            return false;
        }

        int index = freeSpot;
        freeSpot = next[index];
        arr[index] = val;

        next[index] = top[s - 1];
        top[s - 1] = index;

        return true;
    }

    int pop(int s)
    {
        if(top[s - 1] == -1) 
        {
            cout << "Stack underflowed" << endl;
            return -1;
        }

        int index = top[s - 1];
        top[s - 1] = next[index];
        int val = arr[index];
        next[index] = freeSpot;
        freeSpot = index;

        return val;
    }

    ~NStack()
    {
        delete[] arr;
        delete[] top;
        delete[] next;
    }
};

int main()
{
    NStack s(6, 3);

    cout << s.push(10, 1) << endl;
    cout << s.push(20, 1) << endl;
    cout << s.push(30, 1) << endl;
    cout << s.push(40, 2) << endl;
    cout << s.push(50, 3) << endl;
    cout << s.push(60, 3) << endl;
    cout << s.push(70, 3) << endl;
    cout << s.pop(2) << endl;
    cout << s.pop(2) << endl;

    return 0;
}