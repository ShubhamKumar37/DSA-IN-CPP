#include<IOSTREAM>
#include<VECTOR>

using namespace std;

int merge(vector<int> &arr, int s, int mid, int e, vector<int> &temp)
{
    int i = s;
    int j = mid + 1;
    int k = s;
    int count = 0;

    while(i <= mid && j <= e)
    {
        if(arr[i] < arr[j]) temp[k++] = arr[i++];
        else
        {
            count += (mid - i + 1);
            temp[k++] = arr[j++];
        }
    }

    while(i <= mid) temp[k++] = arr[i++];
    while(j <= e) temp[k++] = arr[j++];

    k = s;
    i = s;
    while(k <= e)
    {
        arr[i++] = temp[k++];
    }

    return count;
}

int mergeSort(vector<int> &arr, int s, int e, vector<int> &temp)
{
    if(s >= e) return 0;

    int mid = s + ((e - s) >> 1);
    int count = 0;

    count += mergeSort(arr, s, mid, temp);
    count += mergeSort(arr, mid + 1, e, temp);

    count += merge(arr, s, mid, e, temp);

    return count;
}

int main()
{
    vector<int> arr = {5, 4, 6, 7, 8, 2};
    vector<int> temp(arr.size());

    cout << "Number of inversion required to make sorted array = " << mergeSort(arr, 0, arr.size() - 1, temp);


    return 0;
}