/**
 * @brief 
 *  987. Vertical Order Traversal of a Binary Tree
 
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
    void createTraversal(TreeNode* root, map<int, map<int, vector<int>>> &map, int level, int nodeNum)
    {
        if(!root) return ;
        map[level][nodeNum].push_back(root -> val);

        createTraversal(root -> left, map, level - 1, nodeNum + 1);
        createTraversal(root -> right, map, level + 1, nodeNum + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, vector<int>>> map;
        
        createTraversal(root, map, 0, 0);

        for(auto i : map)
        {
            vector<int> temp;
            for(auto j : i.second)
            {
                sort(j.second.begin(), j.second.end());
                for(auto k : j.second) temp.push_back(k);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        vector<vector<int>> ans;
        map<int, vector<int>> map;
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                Node* front = q.front().first;
                int level = q.front().second;
                q.pop();
                
                map[level].push_back(front -> data);
                if(front -> left) q.push({front -> left, level - 1});
                if(front -> right) q.push({front -> right, level + 1});
            }
        }
        
        for(auto i : map) ans.push_back(i.second);
        return ans;
    }
};


