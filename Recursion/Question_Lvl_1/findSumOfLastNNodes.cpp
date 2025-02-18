// Given a single linked list, calculate the sum of the last n nodes.

// Note: It is guaranteed that n <= number of nodes.

class Solution
{
public:
    /*Structure of the node of the linled list is as

    struct Node {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }
    };
    */
    // your task is to complete this function
    // function should return sum of last n nodes
    int sumOfLastN_Nodes(struct Node *head, int n)
    {
        // Code here
        int sum = 0;
        Node *prev = head;
        Node *curr = head;

        while (curr != nullptr)
        {
            if (n != 0)
                n--;
            else
                prev = prev->next;
            curr = curr->next;
        }

        while (prev != nullptr)
        {
            sum += prev->data;
            prev = prev->next;
        }

        return sum;
    }

    ListNode* mergeNodes(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head -> next;
        int sum = 0;

        while(fast != nullptr)
        {
            if(fast -> val != 0)
            {
                sum += fast -> val;
            }
            else
            {
                slow -> val = sum;
                if(fast -> next != nullptr)slow = slow -> next;
                sum = 0;
            }
            fast = fast -> next;  
        }

        ListNode* newSlow = slow -> next; 
        slow -> next = nullptr;

        while(newSlow != nullptr)
        {
            ListNode* toDelete = newSlow;
            newSlow = newSlow -> next;
            toDelete = nullptr;
            delete toDelete;
        }

        return head;
        
    }
};