/** 
 * 1008. Construct Binary Search Tree from Preorder Traversal
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

    TreeNode* buildTree(vector<int> &preorder, int &index, int min, int max)
    {
        if(index >= preorder.size()) return nullptr;

        TreeNode* newNode = nullptr;

        if(preorder[index] > min && preorder[index] < max) 
        {
            newNode = new TreeNode(preorder[index++]);
            newNode -> left = buildTree(preorder, index, min, newNode -> val);
            newNode -> right = buildTree(preorder, index, newNode -> val, max);
        }

        return newNode;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return buildTree(preorder, index, INT_MIN, INT_MAX);
    }
};