// 148. Sort List

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
    ListNode *solve(ListNode *head1, ListNode *head2)
    {
        if (head1 == nullptr)
            return head2;
        if (head2 == nullptr)
            return head1;

        ListNode *curr1 = head1->next;
        ListNode *curr2 = head2;
        ListNode *prev = head1;

        while (curr1 != nullptr && curr2 != nullptr)
        {
            if (curr1->val <= curr2->val)
            {
                prev->next = curr1;
                prev = curr1;
                curr1 = curr1->next;
            }
            else
            {
                prev->next = curr2;
                prev = curr2;
                curr2 = curr2->next;
            }
        }

        if (curr1 == nullptr)
        {
            prev->next = curr2;
        }
        else
            prev->next = curr1;

        return head1;
    }

    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
            if (fast)
                fast = fast->next;
        }
        prev->next = nullptr;

        head = sortList(head);
        slow = sortList(slow);

        if (head->val <= slow->val)
            return solve(head, slow);
        return solve(slow, head);
    }
};