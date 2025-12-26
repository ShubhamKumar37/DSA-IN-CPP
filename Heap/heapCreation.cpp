#include<iostream>

using namespace std;

class Heap{
public:
    int size;
    int *arr;
    int index;

    Heap(int size)
    { 
        this -> size = size + 1;
        arr = new int[size + 1];
        this -> index = 0;
    }

    void insert(int);
    void print();
    void del();
};

void Heap :: print()
{
    for(int i = 1; i <= index; i++) cout << arr[i] << " ";
    cout << endl;
}

void Heap :: insert(int val)
{
    if(index + 1 >= size) 
    {
        cout << "It is not possible to add more value in heap" << endl;
        return ;
    }

    arr[++index] = val;
    int parent = (index >> 1);
    while(parent != 0)
    {
        int i = index;
        parent = (i >> 1);
        if(arr[parent] > arr[i]) swap(arr[parent], arr[i]);
        else break;
    }
    cout << "Insert succesfull" << endl;
}



int main()
{
    Heap h = Heap(5);
    int arr[] = {10, 30, 70, 33, 120, 2, 45};
    int n = (sizeof(arr) / sizeof(int));

    for(int i = 0; i < n; i++)
    {
        h.insert(arr[i]);
        h.print();
    }


    return 0;
}