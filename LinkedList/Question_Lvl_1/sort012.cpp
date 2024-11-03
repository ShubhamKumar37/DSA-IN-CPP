void insertAtTail(Node *&head, Node *&tail, Node *temp)
{
    if (head == nullptr)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = tail->next;
    }
}

void printLL(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to sort a linked list of 0s, 1s and 2s.
Node *segregate(Node *head)
{

    // Add code here
    Node *zeroHead = nullptr;
    Node *zeroTail = nullptr;

    Node *oneHead = nullptr;
    Node *oneTail = nullptr;

    Node *twoHead = nullptr;
    Node *twoTail = nullptr;

    Node *temp = head;

    while (temp != nullptr)
    {
        if (temp->data == 0)
        {
            insertAtTail(zeroHead, zeroTail, temp);
        }
        else if (temp->data == 1)
        {
            insertAtTail(oneHead, oneTail, temp);
        }
        else
        {
            insertAtTail(twoHead, twoTail, temp);
        }

        temp = temp->next;
    }

    if (twoTail != nullptr)
        twoTail->next = nullptr;

    if (zeroHead != nullptr)
    {
        if (oneHead != nullptr)
        {
            zeroTail->next = oneHead;
            oneTail->next = twoHead;
        }
        else
        {
            zeroTail->next = twoHead;
        }

        return zeroHead;
    }
    else if (oneHead != nullptr)
    {
        oneTail->next = twoHead;
        return oneHead;
    }

    return twoHead;
}