/**
 * @brief 
 * 108. Convert Sorted Array to Binary Search Tree 
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

    TreeNode* createTree(vector<int>& arr, int s, int e)
    {
        if(s > e) return nullptr;
        else 
        {
            int mid  = s + ((e - s) >> 1);
            TreeNode* root = new TreeNode(arr[mid]);
            root -> left = createTree(arr, s, mid - 1);
            root -> right = createTree(arr, mid + 1, e);
            return root;
        }
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int s = 0, e = nums.size() - 1;
        
        return createTree(nums, s, e);

    }
};