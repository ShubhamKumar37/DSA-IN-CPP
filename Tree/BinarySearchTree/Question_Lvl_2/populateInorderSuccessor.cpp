/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};
*/
class Solution {
  public:
    
    void pointLeftSucc(Node* root)
    {
        if(root == nullptr || root -> left == nullptr) return;
        Node* temp = root -> left;
        while(temp -> right != nullptr) temp = temp -> right;
        temp -> next = root;
    }
    
    void pointCurrWithRight(Node* root)
    {
        if(root == nullptr || root -> right == nullptr) return ;
        
        Node* temp = root -> right;
        while(temp -> left != nullptr) temp = temp -> left;
        root -> next = temp;
    }
    
    void populateNext(Node *root) {
        // code here
        if(root == nullptr) return ;
        
        populateNext(root -> left);
        pointLeftSucc(root);
        pointCurrWithRight(root);
        populateNext(root -> right);
    }
};