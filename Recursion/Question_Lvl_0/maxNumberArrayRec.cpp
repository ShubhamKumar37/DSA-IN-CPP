#include<IOSTREAM>
#include<VECTOR>

using namespace std;

int findMax(vector<int> &arr, int index, int maxNum)
{
    if(index == arr.size()) return maxNum;

    return findMax(arr, index + 1, (arr[index] > maxNum ? arr[index] : maxNum));

}

int findMin(vector<int> &arr, int index, int minNum)
{
    if(index == arr.size()) return minNum;

    return findMin(arr, index + 1, arr[index] > minNum ? minNum : arr[index]);
}
int main()
{
    vector<int> arr = {1, 21, 3, 4, 5, 6, 7, 6, 4, 3, 5, 6, 7, 18, -9, 0};

    // cout << "Max number is " << findMax(arr, 0, INT_MIN);
    cout << "Min number is " << findMin(arr, 0, INT_MAX);


    return 0;
}