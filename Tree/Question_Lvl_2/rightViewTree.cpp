/*
Right View of Binary Tree

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

auto checkNull = [](Node* root) -> bool
{
    return root == nullptr;
};

class Solution {
  public:
  
    void getView(Node* root, vector<int> &ans, int index)
    {
        if(checkNull(root)) return ;
        if(ans.size() == index) ans.push_back(root -> data);
        
        getView(root -> right, ans, index + 1);
        getView(root -> left, ans, index + 1);
    }
  
    vector<int> rightView(Node *root) {
        //  code here
        vector<int> ans;
        getView(root, ans, 0);
        
        return ans;
    }
};