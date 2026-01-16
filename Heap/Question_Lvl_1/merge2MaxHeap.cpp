// User function Template for C++

class Solution {
  public:
  
    void arrangeElements(vector<int> &arr, int ele)
    {
        arr.push_back(ele);
        int i = arr.size() - 1;
        int parent = ((i - 1) >> 1);
        
        while(parent != i && parent >= 0 && arr[parent] < arr[i])
        {
            swap(arr[parent], arr[i]);
            i = parent;
            parent = ((i - 1) >> 1);
        }
    }
  
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        if(a.size() >= b.size())
        {
            for(auto i : b) arrangeElements(a, i);
            return a;
        }
        for(auto i : a) arrangeElements(b, i);
        return b;
        
        
    }
};