/*
Normal BST to Balanced BST
Structure of the Node of the BST is as
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {

  public:
  
    void inorder(Node* root, vector<Node*> &arr)
    {
        if(root == nullptr) return ;
        
        inorder(root -> left, arr);
        arr.push_back(root);
        inorder(root -> right, arr);
    }
  
    Node* buildTree(vector<Node*> &arr, int s, int e)
    {
        if(s > e) return nullptr;
        
        int mid = s + ((e - s) >> 1);
        arr[mid] -> left = buildTree(arr, s, mid - 1);
        arr[mid] -> right = buildTree(arr, mid + 1, e);
        
        return arr[mid];
    }
    
    Node* balanceBST(Node* root) {
        // Code here
        vector<Node*> arr;
        inorder(root, arr);
        
        return buildTree(arr, 0, arr.size() - 1);
    }
};