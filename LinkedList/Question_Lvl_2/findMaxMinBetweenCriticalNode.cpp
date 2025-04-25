/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    bool checkHead(ListNode *head)
    {
        if (head != nullptr && head->next != nullptr && head->next->next != nullptr && head->next->next->next != nullptr)
        {
            return false;
        }
        return true;
    }

    bool isCritical(ListNode *curr, ListNode *prev)
    {
        if (prev->val < curr->val && curr->val > curr->next->val)
            return true;
        if (prev->val > curr->val && curr->val < curr->next->val)
            return true;
        return false;
    }

    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        vector<int> ans(2, -1);
        if (checkHead(head))
            return ans;

        int curr = 2;
        int first = -1;
        int last = -1;
        int prev = -1;
        int mini = INT_MAX;
        ListNode *prevNode = head;
        ListNode *temp = head->next;

        while (temp->next != nullptr)
        {
            if (isCritical(temp, prevNode))
            {
                if (first == -1)
                    first = curr;
                last = curr;
                if (prev != -1)
                {
                    mini = min(mini, curr - prev);
                }
                prev = curr;
            }
            prevNode = temp;
            temp = temp->next;
            curr++;
        }

        if (mini == INT_MAX)
            return ans;
        ans[0] = mini;
        ans[1] = last - first;

        return ans;
    }
};