#include<IOSTREAM>
#include<VECTOR>

using namespace std;

int findMax(vector<int> &arr, int s, int e)
{
    if(s == e) return arr[s];

    int mid = s + ((e - s) >> 1);

    int leftMaxSum = findMax(arr, s, mid);
    int rightMaxSum = findMax(arr, mid + 1, e);

    int maxLeftCrossSum = INT_MIN;
    int maxRightCrossSum = INT_MIN;
    int leftSum = 0;
    int rightSum = 0;

    for(int i = mid; i >= s; i--)
    {
        leftSum += arr[i];
        if(maxLeftCrossSum < leftSum) maxLeftCrossSum = leftSum;
    }
    
    for(int i = mid + 1; i <= e; i++)
    {
        rightSum += arr[i];
        if(maxRightCrossSum < rightSum) maxRightCrossSum = rightSum;
    }

    return max(leftMaxSum, max(rightMaxSum, maxLeftCrossSum + maxRightCrossSum));

}

int main()
{
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Maximum sum of subarray is " << findMax(arr, 0, arr.size() - 1);

    return 0;
}