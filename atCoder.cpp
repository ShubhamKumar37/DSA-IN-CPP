#include<iostream>
#include<vector>
#include<limits>

#define MOD 1000000007

using namespace std;

int findMinSum(const vector<int>& arr, int n, int m, int k, int c)
{
    int sum = 0;

        for(int j = 0; j < k; j++)
    {
        int minValue = 2147483647;
        for(int i = 0; i < n; i++)
        {
            int temp = ((c * j) % MOD + arr[i]) % m;
            minValue = min(minValue, temp);
            if(minValue == 0)
            {
                break;
            }
        }
        sum = (sum + minValue) % MOD;
    }

    return sum;
}

int main()
{
    int n, m, k, c;
    cin >> n >> m >> k >> c;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = findMinSum(arr, n, m, k, c);

    cout << ans << endl;

    return 0;
}
