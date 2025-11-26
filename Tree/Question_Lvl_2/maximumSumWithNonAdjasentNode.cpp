/*
Maximum Non-Adjacent Nodes Sum

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
  
    pair<int, int> findAns(Node* root)
    {
        if(root == nullptr) return {0, 0};
        
        pair<int, int> leftAns = findAns(root -> left);
        pair<int, int> rightAns = findAns(root -> right);
        
        int inc = root -> data + leftAns.second + rightAns.second;
        int exc = max(leftAns.first, leftAns.second) + max(rightAns.first, rightAns.second);
        
        return make_pair(inc, exc);
        
    }
  
    int getMaxSum(Node *root) {
        // code here
        if(root == nullptr) return 0;
        
        pair<int, int> ans = findAns(root);
        
        return max(ans.first, ans.second);
    }
};