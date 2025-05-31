#include <iostream>
#include <queue>
#include <deque>

using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val);
    ~Node();
};

Node::Node(int val)
{
    this -> data = val;
    this -> left = nullptr;
    this -> right = nullptr;
}

Node::~Node()
{
    delete left;
    delete right;
}

Node* createTree()
{
    cout << "Enter the value for the node = " << endl;
    int val;
    cin >> val;

    if(val == -1) return nullptr;
    
    Node* root = new Node(val);
    cout << "Enter value for left subtree" << endl;
    root -> left = createTree();
    
    cout << "Enter value for right subtree" << endl;
    root -> right = createTree();

    return root;
}

void levelOrderTraversal(Node* root)
{
    if(root == nullptr) return ;

    queue<Node* > q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty())
    {
        Node* front = q.front();
        q.pop();
        
        if(front == nullptr)
        {
            cout << endl;
            if(!q.empty()) q.push(nullptr);
        }
        else{
            cout << front -> data << " ";
            if(front -> left) q.push(front -> left);
            if(front -> right) q.push(front -> right);
        }
    }

}

void zigzagTraversal(Node* root)
{
    deque<Node* > d;
    
    d.push_back(root);
    bool flag = false;

    while(!d.empty())
    {
        int n = d.size();
        if(!flag)
        {
            for(int i = 0; i < n; i++)
            {
                Node* front = d.front();
                cout << front -> data << " ";
                
                if(front -> left) d.push_back(front -> left);
                if(front -> right) d.push_back(front -> right);
                d.pop_front();
            }
            flag = !flag;
            cout << endl;
        }
        else{
            for(int i = 0; i < n; i++)
            {
                Node* back = d.back();
                cout << back -> data << " ";
                
                if(back -> right) d.push_front(back -> right);
                if(back -> left) d.push_front(back -> left);
                d.pop_back();
            }
            flag = !flag;
            cout << endl;
        }
    }
}

void traversal(Node* root, int type){
    if(root == nullptr) return;

    switch (type)
    {
    case 1:
        cout << root -> data << " ";
        traversal(root -> left, type);
        traversal(root -> right, type);
        break;

    case 2:
        traversal(root -> left, type);
        cout << root -> data << " ";
        traversal(root -> right, type);
        break;

    case 3:
        traversal(root -> left, type);
        traversal(root -> right, type);
        cout << root -> data << " ";
        break;
    
    case 4:
        levelOrderTraversal(root);
        break;
    case 5:
        zigzagTraversal(root);
        break;
    default:
        break;
    }
}

int main()
{
    // 10 50 40 -1 -1 -1 30 20 -1 -1 -1 
    Node* root;
    root = createTree();
    traversal(root, 1); cout << endl; // Preorder
    traversal(root, 2); cout << endl; // Inorder
    traversal(root, 3); cout << endl; // Postorder
    traversal(root, 4); cout << endl; // Levelorder
    traversal(root, 5); cout << endl; // zigzagorder

    return 0;
}