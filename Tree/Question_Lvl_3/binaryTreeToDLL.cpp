/* Structure for tree and linked list
Binary Tree to DLL
// Best approach but mine is below which i thought
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node()
        : data(0)
        , left(NULL)
        , right(NULL) {}

    Node(int x)
        : data(x)
        , left(NULL)
        , right(NULL) {}
};
 */

// This function should return head to the DLL
class Solution {
  public:
    Node* head = nullptr;
    
    void createDll(Node* root)
    {
        if(root == nullptr) return ;
        
        createDll(root -> right);
        if(head != nullptr) head -> left = root;
        root -> right = head;
        head = root;
        createDll(root -> left);
    }
    
    Node* bToDLL(Node* root) {
        // code here
        createDll(root);
        return head;
        
    }
};

/* Structure for tree and linked list

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node()
        : data(0)
        , left(NULL)
        , right(NULL) {}

    Node(int x)
        : data(x)
        , left(NULL)
        , right(NULL) {}
};
 */

// This function should return head to the DLL
class Solution {
  public:
    pair<Node*, Node*> convertTree(Node* root)
    {
        if(root == nullptr) return {nullptr, nullptr};
        if(root -> left == nullptr && root -> right == nullptr) return {root, root};
        
        pair<Node*, Node*> rightList = convertTree(root -> right);
        pair<Node*, Node*> leftList = convertTree(root -> left);
        
        if(leftList.second != nullptr) leftList.second -> right = root;
        root -> left = leftList.second;
        root -> right = rightList.first;
        if(rightList.first != nullptr) rightList.first -> left = root;
        
        Node* first = leftList.first == nullptr ? root : leftList.first;
        Node* second = rightList.second == nullptr ? root : rightList.second;
        
        return {first, second};
        
    }
  
    Node* bToDLL(Node* root) {
        // code here
        if(root == nullptr) return root;
        pair<Node*, Node*> ans = convertTree(root);
        
        return ans.first;
    }
};