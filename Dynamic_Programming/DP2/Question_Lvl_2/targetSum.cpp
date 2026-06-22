class Solution {
  public:
  
    int solveRec(vector<int> &arr, int target, int ind)
    {
        if(arr.size() == ind) return (target == 0);

        int add = solveRec(arr, target + arr[ind], ind + 1);
        int sub = solveRec(arr, target - arr[ind], ind + 1);

        return add + sub;
    }

    int solveRecMem(vector<int> &arr, int target, int ind, map<pair<int, int>, int> &dp)
    {
        if(arr.size() == ind) return (target == 0);
        if(dp.find({ind, target}) != dp.end()) return dp[{ind, target}];

        int add = solveRecMem(arr, target + arr[ind], ind + 1, dp);
        int sub = solveRecMem(arr, target - arr[ind], ind + 1, dp);

        return dp[{ind, target}] = add + sub;
    }

    int solveTab(vector<int> &arr, int t)
    {
        int n = arr.size();
        map<pair<int, int>, int> dp;
        int sum = accumulate(arr.begin(), arr.end(), 0);
        
        dp[{arr.size(), 0}] = 1;
        for(int ind = n - 1; ind >= 0; ind--)
        {
            for(int target = -sum; target <= sum; target++)
            {
                int add = dp[{ind + 1, target + arr[ind]}];
                int sub = dp[{ind + 1, target - arr[ind]}];

                dp[{ind, target}] = add + sub;
            }
        }

        return dp[{0, t}];
    }
  
    int totalWays(vector<int>& nums, int target) {
        //  code here
        map<pair<int, int>, int> dp;

        return solveTab(nums, target);
        // return solveRecMem(nums, target, 0, dp);
        // return solveRec(nums, target, 0);
        
    }
};