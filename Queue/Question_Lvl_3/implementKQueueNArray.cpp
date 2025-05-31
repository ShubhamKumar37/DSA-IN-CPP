#include <IOSTREAM>

using namespace std;


class KQueue
{
    public:
    int size, freeSpot, k;
    int *arr, *front, *rear, *next;

    KQueue(int size, int k)
    {
        this -> k = k;
        this -> size = size;
        this -> freeSpot = 0;
        this -> arr = new int[size];
        this -> next = new int[size];
        this -> front = new int[k];
        this -> rear = new int[k];

        for(int i = 1; i <= size; i++) next[i - 1] = i;
        for(int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }
        next[size - 1] = -1;
    }

    bool push(int q, int val)
    {
        if(freeSpot == -1) 
        {
            cout << "Queue overflow" << endl;
            return false;
        }

        int index = freeSpot;
        freeSpot = next[index];
        
        if(front[q] == -1) front[q] = index;
        else next[rear[q]] = index;

        next[index] = -1;
        rear[q] = index;
        arr[index] = val;

        return true;
    }

    int pop(int q)
    {
        if(front[q] == -1)
        {
            cout << "Queue underflow" << endl;
            return -1;
        }

        int index = front[q];
        front[q] = next[index];
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }

    ~KQueue()
    {
        delete[] arr;
        delete[] front;
        delete[] rear;
        delete[] next;
    }
};

int main()
{
    KQueue q(8, 3);

    cout << q.push(0, 4) << endl;
    cout << q.push(0, 5) << endl;
    cout << q.push(2, 10) << endl;
    cout << q.push(2, 20) << endl;
    cout << q.push(1, 100) << endl;
    cout << q.push(1, 200) << endl;
    cout << q.push(1, 250) << endl;
    cout << q.push(0, 8) << endl;
    cout << q.push(0, 80) << endl;



    return 0;
}