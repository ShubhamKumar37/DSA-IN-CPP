/**
 * @brief 
 * 103. Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        
        vector<vector<int>> ans;
        deque<TreeNode*> dq;
        bool flag = true;
        dq.push_back(root);

        while(!dq.empty())
        {
            int size = dq.size();
            vector<int> restAns;
            for(int i = 0; i < size; i++)
            {
                TreeNode* temp = nullptr;
                if(flag)
                {
                    temp = dq.front();
                    dq.pop_front();

                    if(temp -> left) dq.push_back(temp -> left);
                    if(temp -> right) dq.push_back(temp -> right);
                }
                else 
                {
                    temp = dq.back();
                    dq.pop_back();

                    if(temp -> right) dq.push_front(temp -> right);
                    if(temp -> left) dq.push_front(temp -> left);
                }

                restAns.push_back(temp -> val);
            }
            ans.push_back(restAns);
            flag = !flag;
        }

        return ans;
    }
};