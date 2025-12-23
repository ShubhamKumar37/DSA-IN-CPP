/*
Fixing Two nodes of a BST
class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    Node* prev = nullptr;
    Node* first = nullptr;
    Node* second = nullptr;
  
    void findIncorrect(Node* root)
    {
        if(root == nullptr) return ;
        
        findIncorrect(root -> left);
        if(prev && prev -> data > root -> data)
        {
            if(first == nullptr) first = prev;
            second = root;
        }
        
        prev = root;
        findIncorrect(root -> right);
    }
  
    void correctBST(Node* root) {
        // add code here.
        findIncorrect(root);
        if(first && second) swap(first -> data, second -> data);
    }
};