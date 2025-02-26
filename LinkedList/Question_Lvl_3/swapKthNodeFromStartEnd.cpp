// 1721. Swapping Nodes in a Linked List

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
    ListNode *reverseList(ListNode *head, int val)
    {
        ListNode *curr = head;
        ListNode *forward = head;
        ListNode *prev = nullptr;

        while (val != 0 && curr != nullptr)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            val--;
        }

        return prev;
    }

    int getLength(ListNode *head)
    {
        int count = 0;
        ListNode *temp = head;
        while (temp)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    ListNode *swapNodes(ListNode *head, int k)
    {
        int n = getLength(head);
        if (k == (n - k + 1))
            return head;

        k = k <= (n >> 1) ? k : (n - k + 1);

        if (k == 1)
        {
            ListNode *lastNode = head;
            head = reverseList(head, n);
            head->next = reverseList(head->next, n - k - 1);
            ListNode *temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = lastNode;
            return head;
        }
        else
        {
            ListNode *curr1 = head;
            ListNode *curr2 = head;
            ListNode *temp = head;
            int i = 1;
            while (i != k - 1)
            {
                curr1 = curr1->next;
                i++;
            }
            i = 0;
            while (i != (n - k + 1))
            {
                curr2 = curr2->next;
                i++;
            }

            int val = (n - (2 * (k - 1)));
            curr1->next = reverseList(curr1->next, val);

            i = 0;
            ListNode *newNode = head;
            while (i != (n - k))
            {
                newNode = newNode->next;
                i++;
            }

            curr1 = curr1->next;
            curr1->next = reverseList(curr1->next, val - 2);
            curr1 = head;

            while (curr1->next != nullptr)
                curr1 = curr1->next;
            curr1->next = newNode;
            newNode->next = curr2;
        }

        return head;
    }
};