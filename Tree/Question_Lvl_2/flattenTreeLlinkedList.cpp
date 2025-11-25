// User function Template for C++
// Flatten binary tree to linked list

class Solution {
  public:
    
    Node* getFlatten(Node* root)
    {
        if(root == nullptr) return root;
        
        Node* tempLeft = root -> left;
        Node* tempRight = root -> right;
        
        root -> left = nullptr;
        root -> right = getFlatten(tempLeft);
        
        Node* temp = root;
        while(temp -> right != nullptr) temp = temp -> right;
        temp -> right = getFlatten(tempRight);
        
        return root;
    }
  
    void flatten(Node *root) {
        // code here
        root = getFlatten(root);
    }
};