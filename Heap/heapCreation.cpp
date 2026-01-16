#include <iostream>

using namespace std;

class Heap
{
public:
    int size;
    int *arr;
    int index;

    Heap(int size)
    {
        this->size = size + 1;
        arr = new int[size + 1];
        this->index = 0;
    }

    void insert(int);
    void print();
    void del();
    void heapSort();
};

void heapify(int *&arr, int n, int currIndex)
{

    int i = currIndex;
    int left = 2 * currIndex;
    int right = 2 * currIndex + 1;

    int largeIndex = i;
    if (left <= n && arr[largeIndex] > arr[left])
        largeIndex = left;
    if (right <= n && arr[largeIndex] > arr[right])
        largeIndex = right;
    
    if (largeIndex != i)
    {
        swap(arr[largeIndex], arr[i]);
        i = largeIndex;
        heapify(arr, n, i);
    }
}

void Heap ::heapSort()
{
    cout << "Start heap sort" << endl;
    cout << index << endl;
    for (int i = index; i > 0; i--)
    {
        swap(arr[i], arr[1]);
        heapify(arr, index, 1);
    }
    cout << "End Heap sort" << endl;
}

void Heap ::del()
{
    if (index == 0)
    {
        cout << "Heap is empty" << endl;
        return;
    }

    swap(arr[1], arr[index--]);
    heapify(arr, index, 1);

    cout << "Delete done" << endl;
}

void Heap ::print()
{
    for (int i = 1; i <= index; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void Heap ::insert(int val)
{
    if (index + 1 >= size)
    {
        cout << "It is not possible to add more value in heap" << endl;
        return;
    }

    arr[++index] = val;
    int i = index;
    int parent = (index >> 1);
    while (parent > 0)
    {
        parent = (i >> 1);
        if (arr[parent] < arr[i])
        {
            swap(arr[parent], arr[i]);
            i = parent;
            parent = (i >> 1);
        }
        else
            break;
    }
    cout << "Insert succesfull" << endl;
}

int main()
{
    Heap h = Heap(5);
    int arr[] = {10, 30, 70, 33, 120, 2, 45};
    int n = (sizeof(arr) / sizeof(int));

    for (int i = 0; i < n; i++)
    {
        h.insert(arr[i]);
        h.print();
    }

    // h.del(); 
    // h.print();
    // h.del();
    // h.print();
    // h.del();
    // h.print();
    // h.del();
    // h.print();
    // h.del();
    // h.print();
    // h.del();
    // h.print();

    h.heapSort();
    h.print();

    return 0;
}