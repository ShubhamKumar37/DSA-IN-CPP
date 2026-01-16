// 973. K Closest Points to Origin

class Compare
{
    public:
    bool operator()(vector<int> &a, vector<int> &b)
    {
        int dista = a[0] * a[0] + a[1] * a[1];
        int distb = b[0] * b[0] + b[1] * b[1];
        return dista > distb;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        vector<vector<int>> ans;

        for(auto i : points) pq.push({i[0], i[1]});

        for(int i = 0; i < k; i++)
        {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};