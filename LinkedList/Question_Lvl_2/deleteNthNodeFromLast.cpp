// Given the head of a linked list, remove the nth node from the end of the list and return its head.

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == nullptr)
            return head;

        ListNode *slow = head;
        ListNode *fast = head;
        int count = 0;

        while (count < n && fast != nullptr)
        {
            fast = fast->next;
            count++;
        }

        if (fast == nullptr)
        {
            ListNode *deleteNode = slow;
            slow = slow->next;
            delete deleteNode;
            return slow;
        }

        while (fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *deleteNode = slow->next;
        slow->next = deleteNode->next;
        delete deleteNode;

        return head;
    }

    void removeNode(ListNode *currHead, ListNode *prevHead, int &n)
    {
        if (currHead == nullptr)
            return;
        removeNode(currHead->next, currHead, n);

        n--;
        if (n == 0 && currHead != prevHead)
        {
            prevHead->next = currHead->next;
            currHead->next = nullptr;
            delete currHead;
            n = INT_MAX;
        }
    }

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == nullptr)
            return head;
        ListNode *temp = head;

        int pos = n;
        removeNode(head, temp, pos);

        if (pos <= 0)
        {
            return head->next;
        }

        return head;
    }
};