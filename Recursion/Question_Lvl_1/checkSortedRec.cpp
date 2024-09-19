#include<IOSTREAM>
#include<VECTOR>

using namespace std;

bool checkSorted(vector<int> &arr, int prevElement, int index)
{
    if(index == arr.size()) return true;

    if(prevElement > arr[index]) return false;

    return checkSorted(arr, arr[index], index + 1);
}

int main()
{
    // O(n) - O(n)
    vector<int> arr = {11, 2, 3, 4, 5, 6, 7};
    // vector<int> arr = {11};

    if(checkSorted(arr, arr[0], 1))
    {
        cout << "Array is sorted " << endl;
    }
    else
    {
        cout << "Array is not sorted" << endl;
    }


    return 0;
}