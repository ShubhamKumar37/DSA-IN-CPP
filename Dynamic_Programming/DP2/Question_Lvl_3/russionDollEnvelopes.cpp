class Solution {
public:

    bool isPossible(vector<vector<int>> &arr, int ind, int prev)
    {
        return arr[ind][0] > arr[prev][0] && arr[ind][1] > arr[prev][1];
    }

    int solveRec(vector<vector<int>> &arr, int ind, int prev)
    {
        if(ind >= arr.size()) return 0;

        int inc = (prev == -1 || isPossible(arr, ind, prev)) ? 1 + solveRec(arr, ind + 1, ind) : 0;
        int exc = solveRec(arr, ind + 1, prev);
        
        return max(inc, exc);
    }
    
    int solveRecMem(vector<vector<int>> &arr, int ind, int prev, vector<vector<int>> &dp)
    {
        if(ind >= arr.size()) return 0;
        if(dp[ind][prev + 1] != -1) return dp[ind][prev + 1];

        int inc = (prev == -1 || isPossible(arr, ind, prev)) ? 1 + solveRecMem(arr, ind + 1, ind, dp) : 0;
        int exc = solveRecMem(arr, ind + 1, prev, dp);
        
        return dp[ind][prev + 1] = max(inc, exc);
    }

    int solveTab(vector<vector<int>> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));

        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = i; j >= -1; j--)
            {
                int inc = (j == -1 || isPossible(arr, i, j)) ? 1 + dp[i + 1][i + 1] : 0;
                int exc = dp[i + 1][j + 1];
                
                dp[i][j + 1] = max(inc, exc);
            }
        }
        return dp[0][0];
    }

    int solveTabOp(vector<vector<int>> &arr)
    {
        int n = arr.size();
        vector<int> curr(n + 2, 0);
        vector<int> next(n + 2, 0);

        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = i; j >= -1; j--)
            {
                int inc = (j == -1 || isPossible(arr, i, j)) ? 1 + next[i + 1] : 0;
                int exc = next[j + 1];
                
                curr[j + 1] = max(inc, exc);
            }
            next = curr;
        }
        return curr[0];

    }
    
    int solveTabOp2(vector<vector<int>> &arr)
    {
        int n = arr.size();
        vector<int> curr(n + 2, 0);

        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = -1; j <= i; j++)
            {
                int inc = (j == -1 || isPossible(arr, i, j)) ? 1 + curr[i + 1] : 0;
                int exc = curr[j + 1];
                
                curr[j + 1] = max(inc, exc);
            }
        }
        return curr[0];

    }

    int solveLinearSearch(vector<vector<int>> &arr)
    {
        int prev = -1;
        int ans = 0;
        
        for(int i = 0; i < arr.size(); i++)
        {
            if(prev == -1) 
            {
                ans++;
                prev = i;
            }
            else if(isPossible(arr, i, prev))
            {
                ans++;
                prev = i;
            }
        }

        return ans;
    }

    static bool comp(vector<int> &a, vector<int> &b)
    {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }

    int solveBinarySearch(vector<vector<int>> &arr){
        vector<int> temp;

        for(int i = 0; i < arr.size(); i++)
        {
            if(temp.empty() || temp.back() < arr[i][1]) temp.push_back(arr[i][1]);
            else
            {
                int index = lower_bound(temp.begin(), temp.end(), arr[i][1]) - temp.begin();
                temp[index] = arr[i][1];
            }
        }

        return temp.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        int n = envelopes.size();

        return solveBinarySearch(envelopes);
        // return solveLinearSearch(envelopes);
        // return solveTabOp2(envelopes);
        // return solveTabOp(envelopes);
        // return solveTab(envelopes);
        // vector<vector<int>> dp(n + 1, vector<int>(n + 2, -1));

        // return solveRecMem(envelopes, 0, -1, dp);
        // return solveRec(envelopes, 0, -1);
    }
};