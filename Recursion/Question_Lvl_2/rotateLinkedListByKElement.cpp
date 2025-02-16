/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
    
        int findLength(ListNode* head)
        {
            ListNode* temp = head;
            int count = 0;
    
            while(temp)
            {
                count++;
                temp = temp -> next;
            }
    
            return count;
        }
    
        ListNode* rotateRight(ListNode* head, int k) {
            if(head == nullptr || head -> next == nullptr) return head;
    
            if(k == 0) return head;
            k = (k % findLength(head));
    
            ListNode* slow = head;
            ListNode* fast = head;
    
            while(fast -> next != nullptr)
            {
                if(k != 0)
                {
                    fast = fast -> next;
                    k--;
                }
                else
                {
                    fast = fast -> next;
                    slow = slow -> next;
                }
            }
    
            fast -> next = head;
            head = slow -> next;
            slow -> next = nullptr;
    
            return head;
    
        }
    };