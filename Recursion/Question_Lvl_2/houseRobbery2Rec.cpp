#include<IOSTREAM>
#include<VECTOR>

using namespace std;

int findMaxProfit(vector<int> arr, int start, int end)
{
    if (start > end) return 0;

    int include = findMaxProfit(arr, start + 2, end) + arr[start];
    int exclude = findMaxProfit(arr, start + 1, end);

    return max(include, exclude);
}

int main()
{
    // vector<int> arr = {4, 3, 5, 4, 6, 7, 8};
    vector<int> arr = {4};
    int size = arr.size();
    int ans = arr[0];

    if(size != 1) 
    {
        int includeFirst = findMaxProfit(arr, 0, size - 2);
        int includeLast = findMaxProfit(arr, 1, size - 1);
        ans = max(includeFirst, includeLast);
    }

    cout << "Maximum profit that can be generated is " << ans << endl;


    return 0;
}