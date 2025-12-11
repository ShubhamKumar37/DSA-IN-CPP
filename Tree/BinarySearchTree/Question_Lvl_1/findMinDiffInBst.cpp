/**
 * @brief 
 * 783. Minimum Distance Between BST Nodes 
 *
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
class Solution {
public:
    int first = -1;
    // int second = -1;
    int ans = INT_MAX;

    void find(TreeNode* root)
    {
        if(root == nullptr) return ;

        find(root -> left);
        if(first == -1) first = root -> val;
        else
        {
            ans = min(ans, abs(first - root -> val));
            first = root -> val;
        }
        find(root -> right);
    }

    int minDiffInBST(TreeNode* root) {
        find(root);
        return ans;
    }
};