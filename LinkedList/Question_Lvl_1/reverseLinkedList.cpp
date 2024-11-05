ListNode *reverse(ListNode *head, ListNode *prev, ListNode *curr)
{
    if (curr == nullptr)
        return prev;

    ListNode *forward = curr->next;
    curr->next = prev;
    return reverse(head, curr, forward);
}

ListNode *reverseList(ListNode *head)
{
    // return reverse(head, nullptr, head);
    ListNode* curr = head;
    ListNode* forward = head -> next;
    ListNode* prev = nullptr;

    while(curr != nullptr)
    {
        forward = curr -> next;
        curr -> next = prev;
        curr = forward;
        prev = curr;
    }

    return prev;

}