/*
Symmetric Tree

class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool findSymmetric(Node* r1, Node* r2)
    {
        if(!r1 && !r2) return true;
        if(!r1 || !r2) return false;
        
        if(r1 -> data != r2 -> data) return false;
        return findSymmetric(r1 -> left, r2 -> right) && findSymmetric(r1 -> right, r2 -> left);
    }
  
    bool isSymmetric(Node* root) {
        // code here
        return findSymmetric(root, root);
    }
};