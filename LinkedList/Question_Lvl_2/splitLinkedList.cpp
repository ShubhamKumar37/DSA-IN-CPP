int getLength(Node* head)
{
    int count = 0;
    Node* temp = head;

    while(temp != nullptr)
    {
        temp  = temp -> next;
        count++;
    }

    return count;
}

vector<Node* > splitLinkedList(Node* head, int k)
{
    int n = getLength(head);
    vector<Node*> ans;
    int part = (n / k);
    int extra = (n % k);

    Node* temp = head;
    Node* prev = head;

    while(k != 0)
    {
        ans.push_back(temp);
        int size = part + extra > 0 ? 1 : 0;
        for(int i = 0; i < size && temp != nullptr; i++)
        {
            prev = temp;
            temp = temp -> next;
        }

        if(prev != nullptr) prev -> next = nullptr;
        k--, extra--;
    }

    return ans;
}