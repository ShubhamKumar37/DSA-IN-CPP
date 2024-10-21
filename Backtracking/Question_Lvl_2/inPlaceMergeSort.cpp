#include<IOSTREAM>
#include<VECTOR>

using namespace std;

void swapGap(vector<int> &arr, int i, int j, int e)
{
    while(j <= e)
    {
        if(arr[i] > arr[j]) swap(arr[i], arr[j]);

        i++, j++;
    }
}

void merge(vector<int> &arr, int s, int e)
{
    int gap = e - s + 1;
    gap = (gap >> 1) + (gap % 2);

    while(true)
    {
        swapGap(arr, s, s + gap, e);
        if(gap == 1) break;

        gap = (gap >> 1) + (gap % 2);
    }
}

void mergeSort(vector<int> &arr, int s, int e)
{
    if(s >= e) return ;

    int mid = s + ((e - s) >> 1);

    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    merge(arr, s, e);
}

int main()
{
    // vector<int> arr = {5, 4, 6, 7, 8, 7, 7, 1};
    vector<int> arr = {-2,3,-5};

    mergeSort(arr, 0, arr.size() - 1);

    for(auto i : arr) cout << i << " ";
    cout << endl;

    return 0;
}