/*
Burning Tree
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  
    int burnTree(Node* root, Node* target, unordered_map<Node*, Node*> &map)
    {
        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        int ans = 0;
        
        q.push(target);
        while(!q.empty())
        {
            int size = q.size();
            
            for(int i = 0; i < size; i++)
            {
                Node* front = q.front();
                q.pop();
                
                if(front != root && visited[map[front]] == false) q.push(map[front]);
                if(front -> left != nullptr && visited[front -> left] == false) q.push(front -> left);
                if(front -> right != nullptr && visited[front -> right] == false) q.push(front -> right);
                
                visited[front] = true;
            }
            ans++;
        }
        
        return ans;
        
    }
  
    Node* createMapping(Node* root, int& target, unordered_map<Node*, Node*> &map)
    {
        queue<Node*> q;
        Node* ans;
        q.push(root);
        map[root] = nullptr;
        
        while(!q.empty())
        {
            Node* front = q.front();
            q.pop();
            
            if(front -> data == target) ans = front;
            if(front -> left)
            {
                map[front -> left] = front;
                q.push(front -> left);
            }
            if(front -> right)
            {
                map[front -> right] = front;
                q.push(front -> right);
            }
        }
        
        return ans;
    }
  
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node*, Node*> map;
        
        Node* tar = createMapping(root, target, map);
        
        int ans = burnTree(root, tar, map);
        return ans == 0 ? ans : ans - 1;
    }
};