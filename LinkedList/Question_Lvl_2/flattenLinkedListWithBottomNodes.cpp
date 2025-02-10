// Given a linked list containing n head nodes where every node in the linked list contains two pointers:
// (i) next points to the next node in the list.
// (ii) bottom pointer to a sub-linked list where the current node is the head.
// Each of the sub-linked lists nodes and the head nodes are sorted in ascending order based on their data.
// Your task is to flatten the linked list such that all the nodes appear in a single level while maintaining the sorted order.

// Note:
// 1. ↓ represents the bottom pointer and -> represents the next pointer.
// 2. The flattened list will be printed using the bottom pointer instead of the next pointer.

class Solution
{
public:
    // Function which returns the  root of the flattened linked list.

    void flatList(Node *&head1, Node *&head2)
    {
        if (head1 == nullptr)
            return;
        if (head1 != nullptr && head2 == nullptr)
            return;

        Node *prev = head1;
        Node *curr1 = head1->bottom;
        Node *curr2 = head2;
        Node *temp = nullptr;

        while (curr1 != nullptr && curr2 != nullptr)
        {
            if (curr1->data <= curr2->data)
            {
                prev->bottom = curr1;
                prev = curr1;
                curr1 = curr1->bottom;
            }
            else
            {
                prev->bottom = curr2;
                prev = curr2;
                curr2 = curr2->bottom;
            }
        }

        if (curr1 == nullptr)
            prev->bottom = curr2;
        else
            prev->bottom = curr1;

        flatList(head1, head2->next);
        head1->next = nullptr;
        head2->next = nullptr;
    }

    Node *flatten(Node *root)
    {
        // Your code here
        if (root == nullptr)
            return nullptr;
        if (root->next == nullptr)
            return root;

        Node *curr1 = root;
        Node *curr2 = root->next;

        if (curr1->data <= curr2->data)
        {
            flatList(curr1, curr2);
        }
        else
            flatList(curr2, curr1);

        return root;
    }

    Node *mergeLinkedList(Node *head1, Node *head2)
    {
        if (!head1)
            return head2;
        if (!head2)
            return head1;

        Node *ans = nullptr;

        if (head1->data <= head2->data)
        {
            ans = head1;
            ans->bottom = mergeLinkedList(head1->bottom, head2);
        }
        else
        {
            ans = head2;
            ans->bottom = mergeLinkedList(head1, head2->bottom);
        }

        return ans;
    }

    Node *flatten(Node *root)
    {
        // Your code here
        if (root == nullptr)
            return nullptr;
        if (root->next == nullptr)
            return root;

        mergeLinkedList(root, root->next);
        flatten(root->next);

        if (root->next)
        {
            if (root->next->next)
                root->next->next = nullptr;
            root->next = nullptr;
        }
        return root;
    }
};