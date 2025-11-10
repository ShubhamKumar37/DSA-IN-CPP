/**
 * @brief 
 * 236. Lowest Common Ancestor of a Binary Tree

 * 
 */
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;

        if(root -> val == p -> val) return root;
        if(root -> val == q -> val) return root;
        TreeNode* leftTree = lowestCommonAncestor(root -> left, p, q);
        TreeNode* rightTree = lowestCommonAncestor(root -> right, p, q);

        if(leftTree != nullptr && rightTree != nullptr) return root;
        if(leftTree == nullptr && rightTree != nullptr) return rightTree;
        if(leftTree != nullptr && rightTree == nullptr) return leftTree;
        else return nullptr;

    }
};