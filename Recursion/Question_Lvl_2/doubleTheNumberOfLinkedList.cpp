// 2816. Double a Number Represented as a Linked List

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
class Solution
{
public:
    int doubleList(ListNode *head)
    {
        if (head == nullptr)
            return 0;

        int carry = doubleList(head->next);
        int ans = carry + (head->val * 2);
        head->val = (ans % 10);
        return ans / 10;
    }

    ListNode *doubleIt(ListNode *head)
    {
        int carry = doubleList(head);

        if (carry == 1)
        {
            ListNode *newHead = new ListNode(carry);
            newHead->next = head;
            return newHead;
        }

        return head;
    }
};