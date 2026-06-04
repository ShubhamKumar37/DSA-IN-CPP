class Solution {
public:
    int solveRec(vector<int> &arr, int ind)
    {
        if(arr.size() == ind) return 0;

        int ans = INT_MIN;
        int total = 0;

        for(int x = 1; x <= 3; x++)
        {
            if(ind + x - 1 == arr.size()) break;
            
            total += arr[ind + x - 1];
            ans = max(ans, total - solveRec(arr, ind + x));
        }

        return ans;
    }

    int solveRecMem(vector<int> &arr, int ind, vector<int> &dp)
    {
        if(arr.size() == ind) return 0;
        if(dp[ind] != -1) return dp[ind];

        int ans = INT_MIN;
        int total = 0;

        for(int x = 1; x <= 3; x++)
        {
            if(ind + x - 1 == arr.size()) break;
            
            total += arr[ind + x - 1];
            ans = max(ans, total - solveRecMem(arr, ind + x, dp));
        }

        return dp[ind] = ans;

    }

    int solveTab(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> dp(n + 1, 0);

        for(int ind = n - 1; ind >= 0; ind--)
        {
            int ans = INT_MIN;
            int total = 0;

            for(int x = 1; x <= 3; x++)
            {
                if(ind + x - 1 == arr.size()) break;
                
                total += arr[ind + x - 1];
                ans = max(ans, total - dp[ind + x]);
            }

            dp[ind] = ans;
        }
        
        return dp[0];
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int ans = solveTab(stoneValue);

        // int n = stoneValue.size();
        // vector<int> dp(n + 1, -1);
        // int ans = solveRecMem(stoneValue, 0, dp);
        // int ans = solveRec(stoneValue, 0);
        
        if(ans < 0) return "Bob";
        if(ans > 0) return "Alice";
        return "Tie";
    }
};

class Solution {
public:

    int solveRec(vector<int> &arr, int i, bool alice)
    {
        if(i == arr.size()) return 0;

        int ans = alice ? INT_MIN : INT_MAX;
        int total = 0;

        for(int x = 1; x <= 3; x++)
        {
            if(i + x - 1 == arr.size()) break;
            total += arr[i + x - 1];

            if(alice) ans = max(ans, total + solveRec(arr, i + x, !alice));
            else ans = min(ans, solveRec(arr, i + x, !alice));
        }

        return ans;
    }
    
    int solveRecMem(vector<int> &arr, int i, bool alice, vector<vector<int>> &dp)
    {
        if(i == arr.size()) return 0;
        if(dp[i][alice] != -1) return dp[i][alice];

        int ans = alice ? INT_MIN : INT_MAX;
        int total = 0;

        for(int x = 1; x <= 3; x++)
        {
            if(i + x - 1 == arr.size()) break;
            total += arr[i + x - 1];

            if(alice) ans = max(ans, total + solveRecMem(arr, i + x, !alice, dp));
            else ans = min(ans, solveRecMem(arr, i + x, !alice, dp));
        }

        return dp[i][alice] = ans;
    }

    int solveTab(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for(int i = n - 1; i >= 0; i--)
        {
            for(int alice = 0; alice <= 1; alice++)
            {
                int ans = alice ? INT_MIN : INT_MAX;
                int total = 0;

                for(int x = 1; x <= 3; x++)
                {
                    if(i + x - 1 == arr.size()) break;
                    total += arr[i + x - 1];

                    if(alice) ans = max(ans, total + dp[i + x][!alice]);
                    else ans = min(ans, dp[i + x][!alice]);
                }

                dp[i][alice] = ans;

            }
        }

        return dp[0][1];
        
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int sum = accumulate(stoneValue.begin(), stoneValue.end(), 0);
        // vector<vector<int>> dp(n + 1, vector<int>(2, -1));

        // int ans = solveRec(stoneValue, 0, true);
        int ans = solveTab(stoneValue);
        // int ans = solveRecMem(stoneValue, 0, true, dp);
        int half = (sum >> 1);

        if(sum % 2 == 0 && (half == ans)) return "Tie";
        else if(ans < (sum - ans)) return "Bob";
        return "Alice";
    }
};