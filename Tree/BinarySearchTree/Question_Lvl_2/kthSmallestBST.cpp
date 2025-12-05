/*
k-th Smallest in BST

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int count = 1;
    int kthSmallest(Node *root, int k) {
        // code here
        if(root == nullptr) return -1;
        
        int left = kthSmallest(root -> left, k);
        
        if(left != -1) return left;
        if(k == count) return root -> data;
        
        count++;
        int right = kthSmallest(root -> right, k);
        
        if(left == -1 && right == -1) return -1;
        if(left != -1 && right == -1) return left;
        else return right;
        
    }
};