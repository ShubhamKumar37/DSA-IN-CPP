/*
Find Sum Pairs Across Two BSTs

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
  
    int count = 0;
    
    void moveWithStack1(stack<Node*> &s, Node* root)
    {
        Node* temp = root;
        while(temp != nullptr)
        {
            s.push(temp);
            temp = temp -> left;
        }
    }
    void moveWithStack2(stack<Node*> &s, Node* root)
    {
        Node* temp = root;
        while(temp != nullptr)
        {
            s.push(temp);
            temp = temp -> right;
        }
    }
    
    
    int countPairs(Node* root1, Node* root2, int x) {
        // code here
        stack<Node*> s1;
        stack<Node*> s2;
        
        Node* temp1 = root1;
        Node* temp2 = root2;
        
        moveWithStack1(s1, temp1);
        moveWithStack2(s2, temp2);

        while(!s1.empty() && !s2.empty())
        {
            Node* first = s1.top();
            Node* second = s2.top();
            
            if(first -> data + second -> data == x)
            {
                count++;
                s1.pop();
                s2.pop();
                moveWithStack1(s1, first -> right);
                moveWithStack2(s2, second -> left);
                
            }
            else if(first -> data + second -> data < x)
            {
                s1.pop();
                moveWithStack1(s1, first -> right);
                
            }
            else
            {
                s2.pop();
                moveWithStack2(s2, second -> left);
            }
        }
        
        return count;
        
    }
};