Node *reverseLL(Node *head)
{
    Node *curr = head;
    Node *forward = head->next;
    Node *prev = nullptr;

    while (curr != nullptr)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

Node* add1ToLL(Node* head)
{
    Node* reverseHead = reverseLL(head);
    Node* temp = reverseHead;
    Node* prev = nullptr;
    int carry = 1;

    while (temp != nullptr)
    {
        int sum = temp -> data + carry;
        temp -> data = sum % 10;
        carry = sum / 10;

        prev = temp;
        temp = temp -> next;
    }

    if(carry != 0)
    {
        Node* newNode = new Node(carry);
        prev -> next = newNode;
    }

    return reverseLL(reverseHead);
    
}