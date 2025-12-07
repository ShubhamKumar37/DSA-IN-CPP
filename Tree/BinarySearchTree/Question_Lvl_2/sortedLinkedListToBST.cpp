/**
 * Definition for singly-linked list.
 * 109. Convert Sorted List to Binary Search Tree
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Very importent/unique approach
class Solution {
public:
    
    int getLength(ListNode* head)
    {
        int count = 0;
        ListNode* temp = head;

        while(temp != nullptr) 
        {
            count++;
            temp = temp -> next;
        }

        return count;
    }

    TreeNode* makeTree(ListNode* &head, int n)
    {
        if(head == nullptr || n <= 0) return nullptr;

        TreeNode* leftSub = makeTree(head, (n >> 1));
        
        TreeNode* newNode = new TreeNode(head -> val);
        newNode -> left = leftSub;
        head = head -> next;

        TreeNode* rightSub = makeTree(head, n - (n >> 1) - 1);
        newNode -> right = rightSub;

        return newNode;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int n = getLength(head);
        return makeTree(head, n);
    }
};


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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int getLength(ListNode* head)
    {
        int count = 0;
        ListNode* temp = head;
        while(temp != nullptr)
        {
            count++;
            temp = temp -> next;
        }

        return count;
    }

    ListNode* getMid(ListNode* head, int mid)
    {
        ListNode* temp = head;
        while(mid != 0)
        {
            temp = temp -> next;
            mid--;
        }
        // cout << mid << "-";
        return temp;
    }

    TreeNode* makeTree(ListNode* head, int start, int end)
    {
        if(start > end) return nullptr;
        
        int mid = start + ((end - start) >> 1);
        TreeNode* newNode = new TreeNode(getMid(head, mid) -> val);
        newNode -> left = makeTree(head, start, mid - 1);
        newNode -> right = makeTree(head, mid + 1, end);
        return newNode;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        if(head == nullptr) return nullptr;

        int n = getLength(head);
        return makeTree(head, 0, n - 1);
    }
};