/*
Transform to sum tree
A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:

    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    
    int changeTree(Node* &root)
    {
        if(root == nullptr) return 0;
        
        int lt = changeTree(root -> left);
        int rt = changeTree(root -> right);
        
        int temp = root -> data;
        root -> data = lt + rt;
        
        return temp + root -> data;
    }
    
    void toSumTree(Node *node) {
        // Your code here
        
        changeTree(node);
    }
};