#include<IOSTREAM>
#include<VECTOR>

using namespace std;

// Bubble sort take O(N^2) time complexity with O(1) space complexity

void printArr(vector<int> &arr)
{
    for(auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

void bubbleSort(vector<int> &arr, int length)
{
    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < length - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                swap(arr[j + 1], arr[j]);
            }
        }
    }
}

int main()
{
    vector<int> arr = {5, 4, 6, 5, 3, 4, 2, 3, 4, 5, 6, 2, 6, 9, 8, 7, 0, 3};
    int length = arr.size();


    printArr(arr);

    bubbleSort(arr, length);

    printArr(arr);

    return 0;
}