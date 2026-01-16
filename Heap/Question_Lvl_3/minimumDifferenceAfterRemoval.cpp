// 2163. Minimum Difference in Sums After Removal of Elements

class Solution {
public:

    void makePrefix(vector<int> &arr, vector<long long > &prefix, long long n)
    {
        priority_queue<long long > maxheap;
        long long sum = 0;
        bool flag = false;
        for(long long i = 0; i < n; i++) 
        {
            maxheap.push(arr[i]);
            sum += arr[i];

        }
        maxheap.push(arr[n]);
        sum += arr[n];
        for(long long i = n; i < arr.size(); i++)
        {
            if(!maxheap.empty() && maxheap.top() > arr[i] && flag)
            {
                sum -= maxheap.top();
                sum += arr[i];
                maxheap.pop();
                maxheap.push(arr[i]);
            }
            prefix[i] = sum == 0 ? -1 : sum;
            flag = true;
        }
    }

    void makeSuffix(vector<int> &arr, vector<long long > &suffix, long long n)
    {
        priority_queue<long long , vector<long long >, greater<long long >> minheap;
        long long sum = 0;
        bool flag = false;
        for(long long i = 0; i < n; i++) 
        {
            minheap.push(arr[arr.size() - i - 1]);
            sum += arr[arr.size() - i - 1];

        }
        minheap.push(arr[arr.size() - n - 1]);
        sum += arr[arr.size() - n - 1];
        for(long long i = n; i < arr.size(); i++)
        {
            if(!minheap.empty() && minheap.top() < arr[arr.size() - i - 1] && flag)
            {
                sum -= minheap.top();
                sum += arr[arr.size() - i - 1];
                minheap.pop();
                minheap.push(arr[arr.size() - i - 1]);
            }
            suffix[arr.size() - i - 1] = sum == 0 ? -1 : sum;
            flag = true;
        }
    }

    void print(vector<long long > &arr)
    {
        for(auto i: arr) cout << i << " ";
        cout << endl;
    }

    long long makeAns(vector<long long > &prefix, vector<long long > &suffix, long long n)
    {
        long long ans = LLONG_MAX;
        for(long long i = n; i < (prefix.size() - n - 1); i++) ans = ans < prefix[i] - suffix[i + 1] ? ans : prefix[i] - suffix[i + 1];

        return ans;
    }

    long long minimumDifference(vector<int>& nums) {
        if(nums.size() < 3) return INT_MAX;
        // if(nums.size() == 3) return makeAns(nums, nums, 0);

        long long n = (nums.size() / 3) - 1;
        vector<long long > prefix(nums.size(), -1);
        vector<long long > suffix(nums.size(), -1);

        makePrefix(nums, prefix, n);
        makeSuffix(nums, suffix, n);

        return makeAns(prefix, suffix, n);
    }
};