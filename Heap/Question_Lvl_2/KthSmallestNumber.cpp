// User function template for C++
// 215 leetcode
class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        
        priority_queue<int> PQ;
        for(int i=0; i<k; i++)
        {
            PQ.push(arr[i]);
        }
        
        for(int i=k; i<arr.size(); i++)
        {
            if(arr[i] < PQ.top())
            {
                PQ.pop();
                PQ.push(arr[i]);
            }
        }
        
        return PQ.top();
    }
};