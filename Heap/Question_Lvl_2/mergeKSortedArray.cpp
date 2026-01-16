
class Node
{
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

class Compare{
    
    public: 
    bool operator()(Node a, Node b)
    {
        return a.data > b.data;
    }
};

class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        int n = mat.size();
        int m = mat[0].size();
        vector<int> ans;
        priority_queue<Node, vector<Node>, Compare> pq;
        
        for(int i = 0; i < mat.size(); i++) pq.push(Node(mat[i][0], i, 0));
        
        while(!pq.empty())
        {
            Node top = pq.top();
            pq.pop();
            
            ans.push_back(top.data);
            if(top.col + 1 < m) pq.push(Node(mat[top.row][top.col + 1], top.row, top.col + 1));
        }
        
        return ans;
        
    }
};