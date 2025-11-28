/**
 * @brief 
 * 863. All Nodes Distance K in Binary Tree
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    unordered_map<TreeNode*, TreeNode*> map;
    unordered_map<TreeNode*, bool> visited;
    vector<int> ans;

    void findChild(TreeNode* root, int k){
        if(root == nullptr || k < 0) return ;
        if(k == 0) 
        {
            // cout << k << endl;
            ans.push_back(root -> val);
            return ;
        }

        if(!visited[root -> left]) findChild(root -> left, k - 1);
        if(!visited[root -> right]) findChild(root -> right, k - 1);
    }
    
    void createMaking(TreeNode* root, TreeNode* parent)
    {
        if(root == nullptr) return ;

        map[root] = parent;
        createMaking(root -> left, root);
        createMaking(root -> right, root);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        int temp = k;
        TreeNode* nodeTemp = target;
        
        visited[target] = true;
        createMaking(root, nullptr);
        findChild(target, temp);
        --temp;
        
        while(temp >= 0)
        {
            TreeNode* parent = map[nodeTemp];
            if(parent == nullptr) break;
            
            visited[parent] = true;
            findChild(parent, temp);
            
            nodeTemp = parent;
            --temp;
        }

        return ans;
    }
};