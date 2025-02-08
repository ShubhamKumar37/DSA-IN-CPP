// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

ListNode *solve(ListNode *head1, ListNode *head2)
{
    ListNode *curr1 = head1->next;
    ListNode *curr2 = head2;
    ListNode *prev = head1;

    while (curr1 != nullptr && curr2 != nullptr)
    {
        if (curr1->val <= curr2->val)
        {
            prev->next = curr1;
            prev = curr1;
            curr1 = curr1->next;
        }
        else
        {
            prev->next = curr2;
            prev = curr2;
            curr2 = curr2->next;
        }
    }

    if (curr1 == nullptr)
    {
        prev->next = curr2;
    }
    else
        prev->next = curr1;

    return head1;
}

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{

    if (list1 == nullptr)
        return list2;
    if (list2 == nullptr)
        return list1;

    if (list1->val <= list2->val)
        return solve(list1, list2);
    return solve(list2, list1);
}