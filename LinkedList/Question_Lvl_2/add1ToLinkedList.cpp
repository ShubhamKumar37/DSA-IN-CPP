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

int plusOne(Node* &head)
{
    if(head -> next == nullptr)
    {
        int sum = head -> data + 1;
        head -> data = (sum % 10);
        return (sum / 10);
    }

    int sum = plusOne(head -> next) + head -> data;
    head -> data = (sum % 10);
    return (sum / 10);
}

Node* add1ToLL(Node* head)
{
    // Node* reverseHead = reverseLL(head);
    // Node* temp = reverseHead;
    // Node* prev = nullptr;
    // int carry = 1;

    // while (temp != nullptr)
    // {
    //     int sum = temp -> data + carry;
    //     temp -> data = sum % 10;
    //     carry = sum / 10;

    //     prev = temp;
    //     temp = temp -> next;
    // }

    Node* prev = head;
    int carry = plusOne(prev);

    if(carry != 0)
    {
        Node* newNode = new Node(carry);
        prev -> next = newNode;
        head = prev;
    }

    return head;
    // return reverseLL(reverseHead);
    
}