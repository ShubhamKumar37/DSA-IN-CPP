/**
 * @brief 
 * 
 * 222. Count Complete Tree Nodes
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// User function Template for C++

class Solution {
  public:
    int countNodes(Node* root) {
        // Write your code here
        if(root == nullptr) return 0;
        
        Node* leftTemp = root;
        Node* rightTemp = root;
        int size = 1;
        
        while(leftTemp -> left != nullptr && rightTemp -> right != nullptr)
        {
            leftTemp = leftTemp -> left;
            rightTemp = rightTemp -> right;
            size++;
        }
        
        if(leftTemp -> left == nullptr && rightTemp -> right == nullptr) return (1 << size) - 1;
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};