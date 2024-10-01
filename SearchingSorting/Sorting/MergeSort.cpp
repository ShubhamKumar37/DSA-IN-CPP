#include<IOSTREAM>
#include<VECTOR>

using namespace std;

void mergeArray(vector<int> &arr, int start, int mid, int end)
{
    vector<int> tempAns;

    int i = start;
    int j = mid + 1;

    while(i < arr.size() && j < arr.size() && i <= mid && j <= end)
    {
        if(arr[i] < arr[j])
        {
            tempAns.push_back(arr[i++]);
        }
        else
        {
            tempAns.push_back(arr[j++]);
        }
    }

    while(i < arr.size() && i <= mid) tempAns.push_back(arr[i++]);
    while(j < arr.size() && j <= end) tempAns.push_back(arr[j++]);
    
    i = 0;
    for(int k = start; k <= end; k++)
    {
        arr[k] = tempAns[i++];
    }
}

void mergeSort(vector<int> &arr, int start, int end)
{
    if(start < end)
    {
        int mid = start + ((end - start) >> 1);

        // Left part
        mergeSort(arr, start, mid);

        // Right part
        mergeSort(arr, mid + 1, end);

        mergeArray(arr, start, mid, end);
    }

    return ;
}

int main()
{
    // vector<int> arr = {5, 4, 6, 7, 5, 3, 2, 2, 7, 6, 8};
    vector<int> arr = {3};
    int n = arr.size();

    mergeSort(arr, 0, n);

    for(auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;


    return 0;
}