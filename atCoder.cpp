class Solution {
public:
    void subset(int idx, vector<vector<int>>& finalAns, vector<int>& nums, vector<int> currentSubset) {
        if(idx >= nums.size()) {
            return ;
        }


        finalAns.push_back(currentSubset);
        for (int i = idx; i < nums.size(); i++) {
            if (i != idx && nums[i] == nums[i - 1]) continue;

            currentSubset.push_back(nums[i]);

            subset(i + 1, finalAns, nums, currentSubset);

            currentSubset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> finalAns;
        vector<int> output;
        sort(nums.begin(), nums.end());  
        subset(0, finalAns, nums, output);  
        return finalAns;  
    }
};
