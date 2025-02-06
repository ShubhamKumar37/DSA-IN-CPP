/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
public:
    Node *flatList(Node *head)
    {
        if (head == nullptr)
            return nullptr;

        Node *curr = head;
        Node *tail = head;

        while (curr != nullptr)
        {
            if (curr->child)
            {
                Node *upLevel = curr->next;
                curr->next = curr->child;
                curr->child->prev = curr;
                Node *lastNode = flatList(curr->child);
                lastNode->next = upLevel;
                if (upLevel)
                    upLevel->prev = lastNode;
                curr->child = nullptr;

                // This will make sure that linked list we traversed in child are not traverse again (also without these the algorithm will still work fine)
                curr = lastNode;
                tail = lastNode;
            }
            else
            {
                tail = curr;
                curr = curr->next;
            }
        }
        return tail;
    }

    Node *flatten(Node *head)
    {
        flatList(head);

        return head;
    }
};