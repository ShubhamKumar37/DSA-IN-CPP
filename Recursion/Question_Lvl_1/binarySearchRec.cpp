#include<IOSTREAM>
#include<VECTOR>

using namespace std;

int findElement(vector<int> &arr, int s, int e, int target)
{
    if(s > e) return -1;

    int mid = s + ((e - s) >> 1);

    if(arr[mid] == target) return mid;
    else if(arr[mid] < target) return findElement(arr, mid + 1, e, target);
    else return findElement(arr, s, mid - 1, target);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target = 9;

    cout << "Element found at index = " << findElement(arr, 0, arr.size() - 1, target);



    return 0;
}