Node* reverseLinkedList(Node* &head)
{
    Node* curr = head;
    Node* forward = head -> next;
    Node* prev = nullptr;

    while (curr != nullptr)
    {
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
    
}

bool checkPalindrome(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast -> next != nullptr)
    {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    Node* curr = head;
    slow = reverseLinkedList(slow);
    
    while(slow != nullptr)
    {
        if(curr -> data != slow -> data) return false;
        curr = curr -> next;
        slow = slow -> next;
    }

    return true;
}