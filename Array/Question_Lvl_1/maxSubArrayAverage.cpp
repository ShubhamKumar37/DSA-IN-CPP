#include <IOSTREAM>
#include <VECTOR>

using namespace std;

void maxSubArrayAverage(vector<int> arr, int length, int k)
{
    double maxAverage = -1 * 1e4;
    int i = 0, j = 0;
    double tempSum = 0;

    while (j < length)
    {
        if (j < k)
        {
            tempSum += arr[j];
        }
        else
        {
            maxAverage = max(maxAverage, (tempSum / k));
            tempSum = tempSum - arr[i++] + arr[j];
        }
        j++;
    }

    maxAverage = max(maxAverage, (tempSum / k));

    cout << "The maximum average of subarray is " << maxAverage << endl;
}

int main()
{
    vector<int> arr = {2, 4, 3, 5, 7, 3, 6, 23, 1};
    int length = arr.size();
    int k = 3;

    maxSubArrayAverage(arr, length, k);

    return 0;
}