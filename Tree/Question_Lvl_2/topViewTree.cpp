/*
Top View of Binary Tree

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        map<int, int> map;
        queue<pair<int, Node*>> q;
        
        int hori = 0;
        int vert = 0;
        
        q.push({vert, root});
        
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            
            Node* temp = front.second;
            if(map.find(front.first) == map.end()) map[front.first] = temp -> data;
            
            if(temp -> left) q.push({front.first - 1, temp -> left});
            if(temp -> right) q.push({front.first + 1, temp -> right});
        }
        
        for(auto i : map) ans.push_back(i.second);
        return ans;
    }
};