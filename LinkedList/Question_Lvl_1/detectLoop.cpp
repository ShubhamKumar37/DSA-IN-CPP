bool detectLoop(Node* head)
{
    unordered_map<Node*, bool> map;
    Node* temp = head;

    while(temp != nullptr)
    {
        if(map[temp] == true) return true;
        map[temp] = true;
        temp = temp -> next;
    }

    return false;
}

bool detectLoop(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while(slow != nullptr && fast != nullptr)
    {
        slow = slow -> next;
        fast = fast -> next;
        if(fast != nullptr) fast = fast -> next;

        if(slow != nullptr && fast != nullptr && slow == fast) return true;
    }

    return false;
}