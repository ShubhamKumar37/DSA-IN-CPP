// Given two linked lists head1 and head2, find the intersection of two linked lists. Each of the two linked lists contains distinct node values.

// Note: The order of nodes in this list should be the same as the order in which those particular nodes appear in input head1 and return null if no common element is present.

class Solution
{
public:
    Node *findIntersection(Node *head1, Node *head2)
    {
        // code here
        unordered_map<int, int> map;
        Node *newHead = new Node(-1);
        Node *temp = newHead;
        Node *curr1 = head1;
        Node *curr2 = head2;

        while (curr2 != nullptr)
        {
            map[curr2->data]++;
            curr2 = curr2->next;
        }

        while (curr1 != nullptr)
        {
            if (map[curr1->data] > 0)
            {
                Node *newNode = new Node(curr1->data);
                temp->next = newNode;
                temp = temp->next;
            }
            curr1 = curr1->next;
        }

        return newHead->next;
    }
};