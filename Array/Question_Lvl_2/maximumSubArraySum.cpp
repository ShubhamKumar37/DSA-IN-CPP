#include <IOSTREAM>
#include <VECTOR>
#include <LIMITS>

using namespace std;

int findMaximumSubArraySum1(vector<int> &arr, int length)
{
    int maxSum = INT_MIN;

    for (int i = 0; i < length; i++)
    {
        int sum = 0;
        for (int j = i; j < length; j++)
        {
            sum += arr[j];
            maxSum = sum > maxSum ? sum : maxSum;
        }
    }

    return maxSum == INT_MIN ? -1 : maxSum;
}

int findMaxSubArraySum_Kaden_Algo(vector<int> &arr, int length)
{
    // This algorithm state the traverse the array normally and calculate the sum of the array
    // but if sum is somehow become < 0 then update the sum with 0 as calculating further is no good
    // and at the same condition calculate the maxSum because may be all elements are -ve so the -1 will
    // be the maximum sub array sum.

    int i = 0, j = 0, maxSum = INT_MIN, temp = 0;

    while (j < length)
    {
        temp += arr[j++];
        maxSum = max(maxSum, temp);

        if (temp < 0)
        {
            j++;
            i = j;
            temp = 0;
        }
    }

    return maxSum;
}

int main()
{
    vector<int> arr = {0, -1};
    int length = arr.size();

    cout << "Maximum subarray sum is " << findMaximumSubArraySum1(arr, length) << endl;
    cout << "Maximum subarray sum is " << findMaxSubArraySum_Kaden_Algo(arr, length) << endl;

    return 0;
}