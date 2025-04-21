#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long isPossibleHeight(vector<long long> &arr, long long k, long long mid)
{
    long long sum = 0;
    for (long long i = 0; i < arr.size(); i++)
        sum += (arr[i] <= mid ? 0 : arr[i] - mid);

    return sum;
}

long long findMaxHeight(vector<long long> &arr, long long n, long long k)
{
    long long s = 0;
    long long e = *max_element(arr.begin(), arr.end());
    long long mid = (s + ((e - s) >> 1));
    long long ans = 0;

    while (s <= e)
    {
        long long woodCollected = isPossibleHeight(arr, k, mid);

        if (woodCollected >= k)
        {
            ans = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;

        mid = (s + ((e - s) >> 1));
    }

    return ans;
}

int main()
{

    long long n, k;
    vector<long long> arr;

    cin >> n >> k;

    for (long long i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        arr.push_back(x);
    }

    cout << findMaxHeight(arr, n, k);

    return 0;
}