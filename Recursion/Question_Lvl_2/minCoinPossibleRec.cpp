#include<IOSTREAM>
#include<VECTOR>
#include<LIMITS>

using namespace std;

void minPossibleCount1(vector<int> &arr, int amount, int index, int count, int &ans)
{
    if(index >= arr.size() || amount < 0) return ;

    if(amount == 0)
    {
        ans = min(count, ans);
        return ;
    }

    if(amount >= arr[index])
    {
        minPossibleCount1(arr, amount - arr[index], index, count + 1, ans);
    }

    minPossibleCount1(arr, amount, index + 1, count, ans);
}

int minPossibleCount2(vector<int> arr, int amount)
{
    if(amount == 0) return 0;

    int minPossible = INT_MAX;

    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] <= amount)
        {
            int ans = minPossibleCount2(arr, amount - arr[i]);

            if(ans != INT_MAX)
            {
                minPossible = min(ans + 1, minPossible);
            }
        }
    }

    return minPossible;
}


int main()
{
    vector<int> arr = {4, 3, 5, 1, 2};
    int amount = 32;
    int ans = INT_MAX;

    // minPossibleCount1(arr, amount, 0, 0, ans);

    // cout << "Minimum possible coin required to make the amount = " << ans << endl;
    // cout << "Minimum possible coin required to make the amount = " << minPossibleCount2(arr, amount) << endl;

    return 0;
}