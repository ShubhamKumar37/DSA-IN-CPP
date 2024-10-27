#include<IOSTREAM>

using namespace std;

int findPossible(int n, int k, int target)
{
    if(n == 0)
    {
        if(target == 0) return 1;
        return 0;
    }

    int ans = 0;

    for(int i = 1; i <= k; i++)
    {
        ans = (ans + findPossible(n - 1, k, target - i)) % 1000000007;
    }

    return ans;
}

int main()
{
    int n = 3;
    int k = 9;
    int target = 20;

    cout << "Number of ways to make target = " << findPossible(n, k, target) << endl;


    return 0;
}