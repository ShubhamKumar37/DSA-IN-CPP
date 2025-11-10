/**
 * @brief 110. Balanced Binary Tree
 * 
 */
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 *
 * /
class Solution {
public:
    int findBalanced(TreeNode* root, bool &ans)
    {
        if(root == nullptr) return 0;

        int leftSubTree = findBalanced(root -> left, ans);
        if(!ans) return 0;
        
        int rightSubTree = findBalanced(root -> right, ans);
        if(!ans) return 0;

        if(abs(leftSubTree - rightSubTree) > 1){
            ans = false;
            return 0;
        }

        return max(leftSubTree, rightSubTree) + 1;
    }

    bool isBalanced(TreeNode* root) {
        bool ans = true;

        findBalanced(root, ans);

        return ans;
    }
};