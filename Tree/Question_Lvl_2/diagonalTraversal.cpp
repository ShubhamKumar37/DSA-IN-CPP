/* A binary tree node
Diagonal traversal of binary tree

struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    vector<int> diagonal(Node *root) {
        // code here
        if(!root) return {};
        
        vector<int> ans;
        queue<Node*> q;
        
        q.push(root);
        while(!q.empty())
        {
            Node* front = q.front();
            q.pop();
            
            ans.push_back(front -> data);
            if(front -> left) q.push(front -> left);
            
            while(front -> right != nullptr)
            {
                front = front -> right;
                if(front -> left) q.push(front -> left);
                ans.push_back(front -> data);
            }
        }
        
        return ans;
    }
};