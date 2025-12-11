/**
 * @brief 
 * 1373. Maximum Sum BST in Binary Tree 
 *
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


class FourVal
{
    public:
        int maxVal;
        int minVal;
        bool isBst;
        int sum;
        FourVal(int miv, int mav, bool bst, int s)
        {
            maxVal = mav;
            minVal = miv;
            isBst = bst;
            sum = s;
        }
};

auto checkLeft = [](TreeNode* root) -> bool{
    return root -> left != nullptr;
};
auto checkRight = [](TreeNode* root) -> bool{
    return root -> right != nullptr;
};

class Solution {
public:

    int ans = 0;

    FourVal findSol(TreeNode* root)
    {
        if(root == nullptr) return FourVal(INT_MAX, INT_MIN, true, 0);

        int data = root -> val;
        FourVal left = findSol(root -> left);
        FourVal right = findSol(root -> right);
        bool checkLeftVal = left.maxVal < data;
        bool checkRightVal = right.minVal > data;

        int currSum = data + left.sum + right.sum;
        int minVal = min(data, left.minVal);
        int maxVal = max(data, right.maxVal);
        bool isCurrBst = left.isBst && right.isBst && checkLeftVal && checkRightVal;
        if(isCurrBst) ans = max(ans, currSum);
        return FourVal(minVal, maxVal, isCurrBst, currSum);
        
    }

    int maxSumBST(TreeNode* root) {
        findSol(root);
        return ans < 0 ? 0 : ans;
    }
};