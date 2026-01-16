// 632. Smallest Range Covering Elements from K Lists
class Node{
    public:
    int data;
    int row;
    int col;
    Node(int data, int row, int col)
    {
        this -> data = data;
        this -> row = row;
        this -> col = col;
    }
};

class Compare
{
    public:
    bool operator()(Node* a, Node* b)
    {
        return a -> data > b -> data;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Node*, vector<Node*>, Compare> pq;

        int rows = nums.size();
        int maxVal = INT_MIN;
        int minRange = INT_MAX;
        vector<int> ans;

        for(int i = 0; i < rows; i++)
        {
            pq.push(new Node(nums[i][0], i, 0));
            maxVal = max(maxVal, nums[i][0]);
        }

        while(!pq.empty())
        {
            Node* top = pq.top();
            int diff = maxVal - top -> data;
            pq.pop();

            if(ans.empty()) 
            {
                ans.push_back(top -> data);
                ans.push_back(maxVal);
                minRange = diff;
            }
            else if(minRange > diff)
            {
                ans[0] = top -> data;
                ans[1] = maxVal;
                minRange = diff;
            }
            
            if(top -> col + 1 >= nums[top -> row].size()) break;
            
            int nextVal = nums[top -> row][top -> col + 1];
            pq.push(new Node(nextVal, top -> row, top -> col + 1));
            maxVal = max(maxVal, nextVal);
        }

        return ans;
    }
};