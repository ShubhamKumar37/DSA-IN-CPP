/** 100 Same Tree
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        if(p == nullptr || q == nullptr) return false;

        if(p -> val != q -> val) return false;
        bool lt = isSameTree(p -> left, q -> left);
        bool rt = isSameTree(p -> right, q -> right);

        return lt && rt;

    }
};

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
    bool isIdentical(Node* r1, Node* r2) {
        // code here
        if(r1 == nullptr && r2 == nullptr) return true;
        if(r1 == nullptr || r2 == nullptr) return false;
        if(r1 -> data != r2 -> data) return false;
        
        bool lt = isIdentical(r1 -> left, r2 -> left);
        bool rt = isIdentical(r1 -> right, r2 -> right); 
        
        return lt && rt;
    }
};