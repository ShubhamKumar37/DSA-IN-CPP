#include<IOSTREAM>
#include<VECTOR>

using namespace std;

int findPivot(vector<int> &arr, int length)
{
    int s = 0, e = length - 1;
    
    while(s < e)
    {
        int mid = s + ((e - s) >> 1);

        if(arr[0] <= arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }

    return s;
}

int findElement(vector<int> &arr, int s, int e, int target)
{
    // cout << s << ", " << e << endl;
    while(s <= e)
    {
        int mid = s + ((e - s) >> 1);


        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid] < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }


    return -1;
}


// int findPivot(vector<int> &arr, int length)
// {

//     int s = 0, e = length - 1;

//     while(s <= e)
//     {
//         int mid = s + ((e - s) >> 1);

//         if(mid + 1 < length && arr[mid] > arr[mid + 1])
//         {
//             return mid;
//         }
//         else if(mid - 1 >= 0 && arr[mid] < arr[mid - 1])
//         {
//             return mid - 1;
//         }
//         else if(arr[s] < arr[mid])
//         {
//             e = mid - 1;
//         }
//         else
//         {
//             s = mid + 1;
//         }
//     }

//     return e;
// }

int main()
{
    vector<int> arr = {3, 1};
    int length = arr.size();
    int target = 3;

    if(length == 1)
    {
        cout << "Target element is found at " << (arr[0] == target ? 0 : -1) << endl;
        return 0;
    }

    int pivotIndex = findPivot(arr, length);

    cout << "Pivot element is " << arr[pivotIndex] << endl;

    cout << "Target is present at index = ";


    if(pivotIndex > 0 && pivotIndex < length - 1)
    {
        if(arr[pivotIndex] <= target)
        {
            cout << findElement(arr, pivotIndex, length - 1, target) << endl;
        }
        else
        {
            cout << findElement(arr, 0, pivotIndex, target) << endl;
        }
    }
    else
    {
        if(arr[pivotIndex] > arr[0])
        {
            cout << findElement(arr, 0, length - 1, target);
        }
        else
        {
            if(arr[pivotIndex] == target)
            {
                cout << pivotIndex  << endl;
            }
            else
            {
                cout << findElement(arr, 0, length - 2, target) << endl;
            }
        }
    }
    

    return 0;
}