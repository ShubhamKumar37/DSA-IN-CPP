#include<iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this -> data = data;
        this -> right = nullptr;
        this -> left = nullptr;
    }
};

Node* createTree(Node* &root, int val)
{
    if(root == nullptr) 
    {
        Node* newNode = new Node(val);
        return newNode;
    }

    if(root -> data > val) root -> left = createTree(root -> left, val);
    else if(root -> data < val) root -> right = createTree(root -> right, val);
    return root;
}

void inorder(Node* root)
{
    if(root == nullptr) return ;

    inorder(root -> left);
    cout << root -> data << "-";
    inorder(root -> right);
}

int main()
{
    Node* root = new Node(10);
    int arr[] = {5, 3, 4, 7, 6, 8, 1, 2, 9};

    for(auto i : arr) createTree(root, i);
    inorder(root);
    cout << endl;

    return 0;
}