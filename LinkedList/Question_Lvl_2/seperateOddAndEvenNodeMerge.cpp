// Given a singly linked list, the task is to rearrange it in a way that all odd position nodes are together and all even position nodes are together. (Considering 1-based indexing.)

// Note: You should place all odd-positioned nodes first and then the even-positioned ones. Also, the relative order of odd-positioned nodes and even-positioned nodes should be maintained.

class Solution
{
public:
    void rearrangeEvenOdd(Node *head)
    {
        // Your Code here
        if (head->next == nullptr || head->next->next == nullptr)
            return;

        Node *curr1 = head;
        Node *curr2 = head->next;
        Node *evenHead = curr2;

        while (curr1 != nullptr && curr1->next != nullptr && curr1->next->next != nullptr)
        {
            curr1->next = curr2->next;
            curr1 = curr1->next;
            if (curr1)
                curr2->next = curr1->next;
            else
                curr2->next = nullptr;
            curr2 = curr2->next;
        }

        curr1->next = evenHead;
    }
};

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
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
        {
            return head;
        }

        ListNode *curr1 = head;
        ListNode *curr2 = head->next;
        ListNode *evenHead = head->next;
        ListNode *temp = curr2->next;

        while (temp != nullptr)
        {
            curr1->next = temp;
            temp = temp->next;
            curr2->next = temp;
            if (temp != nullptr)
                temp = temp->next;

            curr1 = curr1->next;
            curr2 = curr2->next;
        }

        curr1->next = evenHead;

        return head;
    }
};