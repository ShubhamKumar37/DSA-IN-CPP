/*

Bottom View of Binary Tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

auto checkNull = [](Node* root) -> bool
{
    return root == nullptr;
};

class Solution {
  public:
    
    void getView(Node* root, map<int, pair<int, int>> &map, int hori, int vert)
    {
        if(checkNull(root)) return ;
        
        if(map.find(vert) == map.end()) map[vert] = {hori, root -> data};
        else if(map[vert].first <= hori) map[vert] = {hori, root -> data};
        
        getView(root -> left, map, hori + 1, vert - 1);
        getView(root -> right, map, hori + 1, vert + 1);
    }
  
    vector<int> bottomView(Node *root) {
        // code here
        vector<int> ans;
        map<int, pair<int, int>> map;
        
        getView(root, map, 0, 0);
        
        for(auto i : map) ans.push_back(i.second.second);
        return ans;
    }
};