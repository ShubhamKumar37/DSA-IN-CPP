// 1019. Next Greater Node In Linked List

    ListNode *
    reverseLL(ListNode *head, int &n)
{
    ListNode *curr = head;
    ListNode *prev = nullptr;
    ListNode *forward = head;

    while (curr != nullptr)
    {
        n++;
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

vector<int> nextLargerNodes(ListNode *head)
{
    if (head == nullptr)
        return vector<int>{};

    int n = 0;
    head = reverseLL(head, n);
    ListNode *temp = head;
    vector<int> ans(n, 0);
    stack<int> s;
    s.push(0);
    n--;

    while (temp != nullptr)
    {
        while (s.top() != 0 && temp->val >= s.top())
            s.pop();
        ans[n--] = s.top();
        s.push(temp->val);
        temp = temp->next;
    }

    head = reverseLL(head, n);

    return ans;
}