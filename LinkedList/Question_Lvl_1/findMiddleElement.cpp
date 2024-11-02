Node* findMiddle(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast -> next != nullptr)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    return slow;
}