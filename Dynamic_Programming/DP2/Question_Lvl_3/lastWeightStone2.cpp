class Solution {
public:

    int solveRec(vector<int> &arr, int ind, int currSum, int sum)
    {
        if(currSum > sum) return -1;
        if(ind >= arr.size()) return currSum;

        int inc = solveRec(arr, ind + 1, currSum + arr[ind], sum);
        int exc = solveRec(arr, ind + 1, currSum, sum);
        return max(inc, exc);

    }
    int solveRecMem(vector<int> &arr, int ind, int currSum, int sum, vector<vector<int>> &dp)
    {
        if(currSum > sum) return -1;
        if(ind >= arr.size()) return currSum;
        if(dp[ind][currSum] != -1) return dp[ind][currSum];

        int inc = solveRecMem(arr, ind + 1, currSum + arr[ind], sum, dp);
        int exc = solveRecMem(arr, ind + 1, currSum, sum, dp);
        return dp[ind][currSum] = max(inc, exc);

    }

    int solveTab(vector<int> &arr, int halfSum)
    {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(halfSum + 1, -1));

        for(int i = 0; i <= halfSum; i++) dp[n][i] = i;

        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = halfSum; j >= 0; j--)
            {
                int inc = j + arr[i] <= halfSum ? dp[i + 1][j + arr[i]] : -1;
                int exc = dp[i + 1][j];
                dp[i][j] = max(inc, exc);
            }
        }
        return dp[0][0];
    }
    int solveTabOp(vector<int> &arr, int halfSum)
    {
        int n = arr.size();
        
        vector<int> curr(halfSum + 1, -1);
        vector<int> next(halfSum + 1, -1);

        for(int i = 0; i <= halfSum; i++) next[i] = i;

        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = halfSum; j >= 0; j--)
            {
                int inc = j + arr[i] <= halfSum ? next[j + arr[i]] : -1;
                int exc = next[j];
                curr[j] = max(inc, exc);
            }
            next = curr;
        }
        return curr[0];
    }
    int solveTabOp2(vector<int> &arr, int halfSum)
    {
        int n = arr.size();

        // vector<int> curr(halfSum + 1, -1);
        vector<int> next(halfSum + 1, -1);

        for(int i = 0; i <= halfSum; i++) next[i] = i;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= halfSum; j++)
            {
                int inc = j + arr[i] <= halfSum ? next[j + arr[i]] : -1;
                int exc = next[j];
                next[j] = max(inc, exc);
            }
        }
        return next[0];
    }

    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int halfSum = (sum >> 1);
        vector<vector<int>> dp(stones.size() + 1, vector<int>(halfSum + 1, -1));
 
        int ans = solveTabOp2(stones, halfSum);
        // int ans = solveTabOp(stones, halfSum);
        // int ans = solveTab(stones, halfSum);
        // int ans = solveRecMem(stones, 0, 0, halfSum, dp);
        // int ans = solveRec(stones, 0, 0, halfSum);

        return abs((sum - ans) - ans);
    }
};

class Solution {
public:

    int solveRec(vector<int> &arr, int ind, int val)
    {
        if(ind >= arr.size()) return val;

        int minus = solveRec(arr, ind + 1, abs(val - arr[ind]));
        int add = solveRec(arr, ind + 1, val + arr[ind]);

        return min(minus, add);
    }
    
    int solveRecMem(vector<int> &arr, int ind, int val, vector<vector<int>> &dp)
    {
        if(ind >= arr.size()) return val;

        if(dp[ind][val] != -1) return dp[ind][val];

        int minus = solveRecMem(arr, ind + 1, abs(val - arr[ind]), dp);
        int add = solveRecMem(arr, ind + 1, val + arr[ind], dp);

        return dp[ind][val] = min(minus, add);
    }

    int solveTab(vector<int> &arr)
    {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        for(int i = 0; i <= sum; i++) dp[n][i] = i;

        // ind = 0 -> n; n - 1 -> 0
        // sum = 0 -> sum; sum - 1 -> 0;
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = sum - arr[i]; j >= 0; j--)
            {
                int minus = dp[i + 1][abs(j - arr[i])];
                int add = dp[i + 1][j + arr[i]];

                dp[i][j] = min(minus, add);
            }
        }

        return dp[0][0];
    }

    int solveTabOp(vector<int> &arr)
    {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        int n = arr.size();
        // vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        vector<int> curr(sum + 1, 0);
        vector<int> next(sum + 1, 0);

        for(int i = 0; i <= sum; i++) next[i] = i;

        // ind = 0 -> n; n - 1 -> 0
        // sum = 0 -> sum; sum - 1 -> 0;
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = sum - arr[i]; j >= 0; j--)
            {
                int minus = next[abs(j - arr[i])];
                int add = next[j + arr[i]];

                curr[j] = min(minus, add);
            }
            next = curr;
        }

        return curr[0];
    }
    
    int solveTabOp2(vector<int> &arr)
    {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        int n = arr.size();
        // vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
        // vector<int> curr(sum + 1, 0);
        vector<int> next(sum + 1, 0);

        for(int i = 0; i <= sum; i++) next[i] = i;

        // ind = 0 -> n; n - 1 -> 0
        // sum = 0 -> sum; sum - 1 -> 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= (sum - arr[i]); j++)
            {
                int minus = next[abs(j - arr[i])];
                int add = next[j + arr[i]];

                next[j] = min(minus, add);
            }
            // next = curr;
        }

        return next[0];
    }

    int lastStoneWeightII(vector<int>& stones) {

        // return solveTabOp2(stones); // This is not possible cuase even if 2 states are 
        // depending comletly on next array still if we merge it then next[abs(j - arr[i])] can be less then equalto or greater then equalto j which makes the decision of merging array wrong
        return solveTabOp(stones);
        // return solveTab(stones);

        // int sum = accumulate(stones.begin(), stones.end(), 0);
        // int n = stones.size();
        // vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        
        // return solveRecMem(stones, 0, 0, dp);
        // return solveRec(stones, 0, 0);
    }
};