/*

Median of BST

class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  
    int getLength(Node* root)
    {
        int count = 0;
        Node* curr = root;
        
        while(curr != nullptr)
        {
            if(curr -> left == nullptr) 
            {
                count++;
                curr = curr -> right;
            }
            else
            {
                Node* temp = curr -> left;
                while(temp -> right != nullptr && temp -> right != curr) temp = temp -> right;
                
                if(temp -> right == nullptr)
                {
                    temp -> right = curr;
                    curr = curr -> left;
                }
                else
                {
                    count++;
                    temp -> right = nullptr;
                    curr = curr -> right;
                }
                
            }
        }
        
        return count;
    }
  
    int findMedian(Node* root) {
        // Code here
        int n = getLength(root);
        
        if(n & 1) n = (n + 1) >> 1;
        else n = n >> 1;
        
        int count = 0;
        int ans = 0;
        Node* curr = root;
        
        while(curr != nullptr)
        {
            if(curr -> left == nullptr) 
            {
                count++;
                if(count == n)
                {
                    ans = curr -> data;
                    break;
                }
                curr = curr -> right;
            }
            else
            {
                Node* temp = curr -> left;
                while(temp -> right != nullptr && temp -> right != curr) temp = temp -> right;
                
                if(temp -> right == nullptr)
                {
                    temp -> right = curr;
                    curr = curr -> left;
                }
                else
                {
                    count++;
                    if(count == n)
                    {
                        ans = curr -> data;
                        break;
                    }
                    temp -> right = nullptr;
                    curr = curr -> right;
                }
                
            }
            
        }
            return ans;
        
        
    }
};