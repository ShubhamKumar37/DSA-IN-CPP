/**
 * @brief 
 * 94. Binary Tree Inorder Traversal 
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        
        while(curr != nullptr)
        {
            if(curr -> left == nullptr)
            {
                ans.push_back(curr -> val);
                curr = curr -> right;
            }
            else
            {
                TreeNode* nextNode = curr -> left;
                while(nextNode -> right != curr && nextNode -> right != nullptr) nextNode = nextNode -> right;

                if(nextNode -> right == nullptr)
                {
                    nextNode -> right = curr;
                    curr = curr -> left;
                }
                else
                {
                    nextNode -> right = nullptr;
                    ans.push_back(curr -> val);
                    curr = curr -> right;
                }
            }

        }
        return ans;
    }
};