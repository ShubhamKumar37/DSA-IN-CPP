// Given a linked list, delete n nodes after skipping m nodes of a linked list until the last of the linked list.

class Solution
{
public:
    Node *linkdelete(Node *head, int n, int m)
    {
        // code here
        if (m == 0)
            m = 1;

        int num = 1;
        Node *curr = head;

        while (curr != nullptr)
        {
            if (num != m)
                num++;
            else
            {
                Node *temp = curr->next;
                int count = 0;
                while (temp != nullptr && count != n)
                {
                    Node *toBeDeleted = temp;
                    temp = temp->next;
                    curr->next = temp;
                    count++;

                    delete toBeDeleted;
                }
                num = 1;
            }

            curr = curr->next;
        }

        return head;
    }

    Node *linkdelete(Node *head, int n, int m)
    {
        // code here
        if (head == nullptr)
            return head;

        Node *curr = head;
        for (int i = 1; i < m && curr != nullptr; i++)
            curr = curr->next;
        if (curr == nullptr)
            return head;

        Node *temp = curr->next;
        for (int i = 0; i < n && temp != nullptr; i++)
        {
            Node *deleteNode = temp;
            temp = temp->next;
            delete deleteNode;
        }

        curr->next = linkdelete(temp, n, m);
        return head;
    }
};
