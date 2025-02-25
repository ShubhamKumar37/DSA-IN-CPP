// 1171. Remove Zero Sum Consecutive Nodes from Linked List

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
    void deleteEntry(ListNode *start, ListNode *end, unordered_map<int, ListNode *> &map, int &prefixSum)
    {
        if (start == nullptr)
            return;
        if (start == end)
        {
            prefixSum -= start->val;
            return;
        }

        deleteEntry(start->next, end, map, prefixSum);
        map.erase(prefixSum);
        prefixSum -= start->val;
    }

    ListNode *removeZeroSumSublists(ListNode *head)
    {
        ListNode *temp = head;
        ListNode *curr1 = head;
        unordered_map<int, ListNode *> map;
        int prefixSum = 0;

        while (temp)
        {
            prefixSum += temp->val;
            if (prefixSum == 0)
            {
                temp = temp->next;
                head = temp;
                map.clear();
                continue;
            }
            else if (map.find(prefixSum) != map.end())
            {
                ListNode *saveNode = temp->next;
                deleteEntry(map[prefixSum]->next, temp, map, prefixSum);
                map[prefixSum]->next = saveNode;
                temp = map[prefixSum];
            }
            map[prefixSum] = temp;
            temp = temp->next;
        }

        return head;
    }
};