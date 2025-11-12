/**
 * @brief 
 * 105. Construct Binary Tree from Preorder and Inorder Traversal
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
 */
class Solution {
public:

    TreeNode* createTree(vector<int>& preorder, vector<int>& inorder, int &index, int start, int end)
    {
        if(index >= preorder.size()) return nullptr;
        if(start < 0 || end < 0 || start >= inorder.size() || end >= inorder.size()) return nullptr;

        int newEleIndex = -1;
        for(int i = start; i <= end; i++) if(inorder[i] == preorder[index]) {
            newEleIndex = i;
            break;
        }
        if(newEleIndex == -1) return nullptr;
        
        TreeNode* newNode = new TreeNode(preorder[index]);
        index++;
        newNode -> left = createTree(preorder, inorder, index, start, newEleIndex - 1);
        newNode -> right = createTree(preorder, inorder, index, newEleIndex + 1, end);
        return newNode;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        TreeNode* ans = createTree(preorder, inorder, index, 0, inorder.size() - 1);
        return ans;
    }
};