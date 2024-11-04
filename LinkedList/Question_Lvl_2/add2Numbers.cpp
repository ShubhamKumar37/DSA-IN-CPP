class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* newHead = new ListNode(0);
        ListNode* tempHead = newHead;

        while(temp1 != nullptr && temp2 != nullptr)
        {
            int sum = temp1 -> val + temp2 -> val + carry;
            carry = (sum / 10);
            ListNode* newNode = new ListNode((sum % 10));
            tempHead -> next = newNode;
            tempHead = tempHead -> next;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        while(temp1 != nullptr)
        {
            int sum = temp1 -> val + carry;
            carry = (sum / 10);
            ListNode* newNode = new ListNode((sum % 10));
            tempHead -> next = newNode;
            tempHead = tempHead -> next;
            temp1 = temp1 -> next;
        }
        while(temp2 != nullptr)
        {
            int sum = temp2 -> val + carry;
            carry = (sum / 10);
            ListNode* newNode = new ListNode((sum % 10));
            tempHead -> next = newNode;
            tempHead = tempHead -> next;
            temp2 = temp2 -> next;
        }
        if(carry != 0)
        {
            ListNode* newNode = new ListNode(carry);
            tempHead -> next = newNode;
        }

        return newHead -> next;
        
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int carry = 0;
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans;

        while(l1 || l2 || carry)
        {
            int d1 = l1 ? l1 -> val : 0;
            int d2 = l2 ? l2 -> val : 0;
            int sum = d1 + d2 + carry;
            carry = (sum / 10);

            ListNode* newNode = new ListNode(sum % 10);
            temp -> next = newNode;
            temp = temp -> next;
            l1 = l1 ? l1 -> next : nullptr;
            l2 = l2 ? l2 -> next : nullptr;
        }

        return ans -> next;
        
    }
};