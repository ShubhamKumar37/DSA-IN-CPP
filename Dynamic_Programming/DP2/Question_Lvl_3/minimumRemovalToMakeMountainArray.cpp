class Solution {
public:

    vector<int> LISLeftToRight(vector<int> &arr)
    {
        vector<int> temp;
        vector<int> ans;

        for(int i = 0; i < arr.size(); i++)
        {
            if(temp.empty() || temp.back() < arr[i])
            {
                temp.push_back(arr[i]);
                ans.push_back(temp.size());
            }
            else
            {
                int index = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                ans.push_back(index + 1);
                temp[index] = arr[i];
            }
        }

        return ans;
    }
    
    vector<int> LISRightToLeft(vector<int> &arr)
    {
        vector<int> temp;
        vector<int> ans;

        for(int i = arr.size() - 1; i >= 0; i--)
        {
            if(temp.empty() || temp.back() < arr[i])
            {
                temp.push_back(arr[i]);
                ans.push_back(temp.size());

            }
            else
            {
                int index = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                ans.push_back(index + 1);
                temp[index] = arr[i];
            }
        }

        return ans;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        
        int ans = INT_MAX;
        vector<int> leftToRight = LISLeftToRight(nums);
        vector<int> rightToLeft = LISRightToLeft(nums);
        
        reverse(rightToLeft.begin(), rightToLeft.end()); // We need to reverse because we are going left R -> L but our 
        // vector in function will always fill from L -> R.

        for(int i = 0; i < nums.size(); i++)
        {
            if(leftToRight[i] == 1 || rightToLeft[i] == 1) continue;
            int val = nums.size() - (leftToRight[i] + rightToLeft[i] - 1);
            ans = min(ans, val);
        }

        return ans;
    }
};

class Solution {
public:

    int LISLeftToRight(vector<int> &arr, int ind)
    {
        vector<int> temp;

        for(int i = 0; i < ind; i++)
        {
            if(arr[ind] > arr[i])
            {
                if(temp.empty() || temp.back() < arr[i]) temp.push_back(arr[i]);
                else
                {
                    int index = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                    temp[index] = arr[i];
                }
            }
        }

        return temp.size();
    }
    
    int LISRightToLeft(vector<int> &arr, int ind)
    {
        vector<int> temp;

        for(int i = arr.size() - 1; i > ind; i--)
        {
            if(arr[ind] > arr[i])
            {
                if(temp.empty() || temp.back() < arr[i]) temp.push_back(arr[i]);
                else
                {
                    int index = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                    temp[index] = arr[i];
                }
            }
        }

        return temp.size();
    }

    int minimumMountainRemovals(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        
        int ans = INT_MAX;
        
        for(int i = 1; i < nums.size() - 1; i++)
        {
            int l1 = LISLeftToRight(nums, i);
            int r1 = LISRightToLeft(nums, i);
            if(l1 != 0 && r1 != 0)
            {
                int left = i - l1;
                int right = (nums.size() - i - 1) - r1;
                ans = min(ans, left + right);
            }
        }

        return ans;
    }
};