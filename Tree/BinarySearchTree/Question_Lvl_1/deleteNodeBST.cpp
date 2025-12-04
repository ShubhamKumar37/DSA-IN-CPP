/*
 * 450. Delete Node in a BST 
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;

        if(root -> val == key)
        {
            if(root -> left == nullptr && root -> right == nullptr) 
            {
                delete root;
                return nullptr;
            }
            else if(root -> left != nullptr && root -> right == nullptr) 
            {
                TreeNode* temp = root -> left;
                delete root;
                return temp;
            }
            else if(root -> left == nullptr && root -> right != nullptr) 
            {
                TreeNode* temp = root -> right;
                delete root;
                return temp;

            }
            else
            {
                TreeNode* temp = root -> left;
                while(temp -> right != nullptr) temp = temp -> right;
                swap(root -> val, temp -> val);
                root -> left = deleteNode(root -> left, temp -> val);
            }
        }
        else 
        {
            if(root -> val > key) root -> left = deleteNode(root -> left, key);
            else root -> right = deleteNode(root -> right, key);
        }

        return root;
    }
};
