/*
Count the nodes at distance K from leaf
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
    unordered_map<Node*, Node*> map;
    unordered_map<Node*, bool> visited;
    int ans = 0;
    
    void createMapping(Node* root, Node* parent)
    {
        if(root == nullptr) return ;
        
        map[root] = parent;
        
        createMapping(root -> left, root);
        createMapping(root -> right, root);
    }
    
    void findSpecialNode(Node* root, int k)
    {
        if(root == nullptr) return;
        if(root -> left == nullptr && root -> right == nullptr) traverseUp(root, k);
        
        findSpecialNode(root -> left, k);
        findSpecialNode(root -> right, k);
    }
    
    void traverseUp(Node* root, int k)
    {
        Node* temp = root;
        while(k != 0 && temp != nullptr)
        {
            temp = map[temp];
            k--;
        }
        if(k == 0 && temp != nullptr && !visited[temp])
        {
            visited[temp] = true;
            ans++;
        }
    }
    
    int kthFromLeaf(Node* root, int k) {
        // code here.
        createMapping(root, nullptr);
        findSpecialNode(root, k);
        
        return ans;
        
    }
};