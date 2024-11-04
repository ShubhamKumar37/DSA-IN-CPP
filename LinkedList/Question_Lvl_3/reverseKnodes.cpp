int getLength(ListNode *head)
{
    int count = 0;
    ListNode *temp = head;

    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

ListNode *revRecByK(ListNode *head, int counter, int k)
{
    if (head == nullptr || counter == 0)
        return head;

    ListNode *curr = head;
    ListNode *prev = nullptr;
    ListNode *forward = head->next;
    int count = 0;
    while (curr != nullptr && count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    if (forward != nullptr)
    {
        head->next = revRecByK(forward, counter - 1, k);
    }

    return prev;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (k == 1)
        return head;
    int n = getLength(head);

    return revRecByK(head, (n / k), k);
}