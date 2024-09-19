#include<IOSTREAM>
#include<VECTOR>

using namespace std;

bool findElement(vector<int> &arr, int &target, int index)
{
    if(index == arr.size()) return false;

    if(arr[index] == target) return true;

    return findElement(arr, target, index + 1);
}

int main()
{
    vector<int> arr = {2, 3, 4, 3, 5, 4, 6, 5, 7, 6, 8, 7};
    int target = 37;

    if(findElement(arr, target, 0))
    {
        cout << "Element is present in the array" << endl;
    }
    else
    {
        cout << "Target is not present in array" << endl;
    }




    return 0;
}