#include<iostream>
#include<VECTOR>

using namespace std;


void printArr(vector<int> &arr, int index)
{
    if(index == arr.size()) return ;

    printArr(arr, index + 1);
    cout << arr[index] << " ";
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    printArr(arr, 0);

    return 0;
}