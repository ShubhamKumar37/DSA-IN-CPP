/*
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
    bool isHeap(Node* root) {
        // code here
        bool flag = true;
        queue<Node*> q;
        
        q.push(root);
        
        while(!q.empty())
        {
            int size = q.size();
            
            for(int i = 0; i < size; i++)
            {
                Node* front = q.front();
                q.pop();
                
                if(front == nullptr) flag = false;
                else 
                {
                    if(flag == false) return false;
                    bool leftCondition = front -> left ? front -> left -> data < front -> data : true;
                    bool rightCondition = front -> right ? front -> right -> data < front -> data : true;
                    
                    if(!(leftCondition && rightCondition)) return false;
                    q.push(front -> left);
                    q.push(front -> right);
                }
            }
        }
        
        return true;
    }
};