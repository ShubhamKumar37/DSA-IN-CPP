/**
 * @brief 
 * 958. Check Completeness of a Binary Tree 
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

    int size = 0;
    void inorder(TreeNode* root)
    {
        if(root == nullptr) return ;

        inorder(root -> left);
        size++;
        inorder(root -> right);
    }
    
    bool check(TreeNode* root, int index)
    {
        if(root == nullptr)
        {
            if(index <= size) return false;
            return true;
        }
        if(index > size) return false;

        bool left = check(root -> left, (index << 1));
        bool right = check(root -> right, (index << 1) + 1);

        return left && right;
    }

    bool isCompleteTree(TreeNode* root) {
        inorder(root);
        return check(root, 1);
    }
};