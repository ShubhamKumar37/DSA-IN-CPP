Node *getList(Node *head)
{
    Node *newHead = head;
    Node *temp = head;

    while (temp != nullptr)
    {
        Node *newNode = new Node(temp->data);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = newNode->next;
    }

    return newHead;
}

Node *joinRandom(Node *head)
{
    Node *curr1 = head;
    Node *curr2 = head->next;
    while (curr2 != nullptr)
    {
        if (curr1->random != nullptr)
        {
            Node *toRandom = curr1->random;
            curr2->random = toRandom->next;
        }
        // First
        if (curr1)
            curr1 = curr1->next;
        if (curr1)
            curr2 = curr2->next;

        // Second
        if (curr1)
            curr1 = curr1->next;
        if (curr2)
            curr2 = curr2->next;
    }
}

Node *solve(Node *head, unordered_map<Node *, Node *> &map)
{
    if (head == nullptr)
        return nullptr;

    Node *newNode = new Node(head->data);
    map[head] = newNode;

    newNode->next = solve(head->next, map);
    if (head->random != nullptr)
    {
        newNode->random = map[head->random];
    }

    return newNode;
}

Node *cloneLinkedList(Node *head)
{
    // Write your code here
    unordered_map<Node *, Node *> map;

    return solve(head, map);
}