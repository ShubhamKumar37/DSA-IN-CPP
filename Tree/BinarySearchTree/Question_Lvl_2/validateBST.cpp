class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    
    bool Check_BST(Node* root, int Min, int Max)
    {
        if(root == NULL)
        {
            return true;
        }
        
        if(root -> data < Max && root -> data > Min)
        {
            bool Left_Tree = Check_BST(root -> left, Min, root -> data);
            bool Right_Tree = Check_BST(root -> right, root -> data, Max);
            return Left_Tree && Right_Tree;
        }
        else
        {
            return false;
        }
    }
    
    bool isBST(Node* root) 
    {
        // Your code here
        int Min = INT_MIN;
        int Max = INT_MAX;
        
        return Check_BST(root, Min, Max);
    }
};



