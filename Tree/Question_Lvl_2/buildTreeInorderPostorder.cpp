/**
 * @brief 
 * 106. Construct Binary Tree from Inorder and Postorder Traversal
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

    TreeNode* createTree(vector<int>& inorder, vector<int> &postorder, int &index, unordered_map<int, int> &map, int start, int end)
    {
        if(index < 0) return nullptr;
        if(start < 0 || end < 0 || start >= inorder.size() || end >= postorder.size()) return nullptr;

        if(map[postorder[index]] < start || map[postorder[index]] > end) return nullptr;

        int newElementIndex = map[postorder[index]];
        TreeNode* newNode = new TreeNode(inorder[newElementIndex]);

        index--;
        newNode -> right = createTree(inorder, postorder, index, map, newElementIndex + 1, end);
        newNode -> left = createTree(inorder, postorder, index, map, start, newElementIndex - 1);

        return newNode;


    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = postorder.size() - 1;
        unordered_map<int, int> map;
        for(int i = 0; i < postorder.size(); i++) map[inorder[i]] = i;
        return createTree(inorder, postorder, index, map, 0, postorder.size() - 1);
    }
};