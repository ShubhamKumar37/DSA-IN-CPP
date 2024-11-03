void deleteNode(Node* &prev, Node* &curr)
{
    prev -> next = curr -> next;
    curr -> next = nullptr;
    delete curr;
}

Node* removeDuplicate(Node* head)
{
    if(head == nullptr) return head;

    Node* prev = head;
    Node* curr = head -> next;

    while(curr != nullptr)
    {
        if(curr -> data == prev -> data)
        {
            // deleteNode(prev, curr);
            // curr = prev -> next;
            // OR
            prev -> next = curr -> next;
            curr = curr -> next;
        }
        else
        {
            curr = curr -> next;
            prev = prev -> next;
        }
    }

    return head;
}