/**
662. Maximum Width of Binary Tree
 * 
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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long>> q;
        int count = 0;
        q.push({root, 1});

        while(!q.empty())
        {
            auto size = q.size();
            auto front = q.front();
            auto back = q.back();

            count = max<int>(count, back.second - front.second + 1);

            for(unsigned long long i = 0; i < size; i++)
            {
                auto qFront = q.front();
                q.pop();
                if(qFront.first -> left) q.push({qFront.first -> left, qFront.second * 2});
                if(qFront.first -> right) q.push({qFront.first -> right, qFront.second * 2 + 1});
            }
        }

        return count;
    }
};