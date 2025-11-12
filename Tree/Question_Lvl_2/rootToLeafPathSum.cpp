/* 
112. Path Sum
A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*you are required to
complete this function */
class Solution {
  public:
    bool hasPathSum(Node *root, int target) {
        // Your code here
        if(root == nullptr) return false;
        if(root -> left == nullptr && root -> right == nullptr)
        {
            if(target - root -> data == 0) return true;
            return false;
        }
        
        bool leftTree = hasPathSum(root -> left, target - root -> data);
        bool rightTree = hasPathSum(root -> right, target - root -> data);
        
        return leftTree || rightTree;
    }
};