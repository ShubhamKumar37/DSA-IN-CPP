#include<IOSTREAM>

using namespace std;


int findMinPossible(int n, int start)
{
    if(n == 0) return 0;
    if(n < 0) return INT_MAX;

    int ans = INT_MAX;

    for(int i = start; n - (i * i) >= 0; i++)
    {
        int recAns = findMinPossible(n - (i * i), i);

        if(recAns != INT_MAX)
        {
            ans = min(ans, recAns + 1);
        }
    }

    return ans;
}

int main()
{
    int n = 12;

    cout << "Perfect Square sum of min count = " << findMinPossible(n, 1) << endl;


    return 0;
}