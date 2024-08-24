#include<IOSTREAM>
#include<VECTOR>

using namespace std;

int findElement(vector<int> &arr,int length, int target)
{
    int s = 0, e = length - 1;
    int mid = s + ((e - s) >> 1);

    while(s <= e)
    {
        if(arr[mid] == target)
        {
            return mid;
        }
        else if(mid - 1 >= 0 && arr[mid - 1] == target)
        {
            return mid - 1;
        }
        else if(mid + 1 < length && arr[mid + 1] == target)
        {
            return mid + 1;
        }
        else if(arr[mid] < target)
        {
            // s = mid + 1; Both are valid
            s = mid + 2;
        }
        else 
        {
            // e = mid - 1; Both are valid
            e = mid - 2;
        }

        mid = s + ((e - s) >> 1);
    }

    return -1;
}

int main()
{
    vector<int> arr = {2, 1, 3, 5, 4, 6};
    int length = arr.size();
    int target = 6;

    cout << "Index found at index = " << findElement(arr, length, target) << endl;



    return 0;
}