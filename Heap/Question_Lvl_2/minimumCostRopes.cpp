class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0;
        for(auto i : arr) pq.push(i);
        
        while(pq.size() != 1)
        {
            int first = pq.top();
            pq.pop();
            if(!pq.empty())
            {
                int sum = first + pq.top();
                ans += (sum);
                pq.pop();
                pq.push(sum);
            }
        }
        
        return ans;
    }
};