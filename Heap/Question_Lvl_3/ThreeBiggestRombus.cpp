// 1878. Get Biggest Three Rhombus Sums in a Grid

class Solution {
public:

    bool inRange(vector<vector<int>> &arr, int row, int col)
    {
        return (row < arr.size() && col < arr[0].size() && row >= 0 && col >= 0);
    }

    int returnUpRight(vector<vector<int>> &arr, int i, int j, int add, int row, int col)
    {
        int sum = 0;

        if(!inRange(arr, i, j)) return -1;
        if((i - add) >= 0 && (j + add) < col)
        {
            for(int k = 0; k < add; k++) sum += arr[--i][++j];
            return sum;
        }
        return -1;
    }

    int returnDownRight(vector<vector<int>> &arr, int i, int j, int add, int row, int col)
    {
        int sum = 0;

        if(!inRange(arr, i, j)) return -1;
        if((i + add < row) && (j + add) < col)
        {
            for(int k = 0; k < add; k++) sum += arr[++i][++j];
            return sum;
        }
        return -1;

    }

    int returnDownLeft(vector<vector<int>> &arr, int i, int j, int add, int row, int col)
    {
        int sum = 0;

        if(!inRange(arr, i, j)) return -1;
        if((i + add < row) && (j - add) >= 0)
        {
            for(int k = 0; k < add; k++) sum += arr[++i][--j];
            return sum;
        }
        return -1;

    }
    int returnUpLeft(vector<vector<int>> &arr, int i, int j, int add, int row, int col)
    {
        int sum = 0;

        if(!inRange(arr, i, j)) return -1;
        if((i - add) >= 0 && (j - add) >= 0)
        {
            for(int k = 0; k < add; k++) sum += arr[--i][--j];
            return sum;
        }
        return -1;

    }
    
    bool checkDup(priority_queue<int, vector<int>, greater<int>> pq, int val)
    {
        while(!pq.empty())
        {
            if(val == pq.top()) return true;
            pq.pop();
        }

        return false;
    }

    void pushEle(priority_queue<int, vector<int>, greater<int>> &pq, int sum)
    {
        if(checkDup(pq, sum)) return ;
        if(pq.size() < 3) pq.push(sum);
        else
        {
            if(pq.top() < sum)
            {
                pq.pop();
                pq.push(sum);
            }
        }
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int row = grid.size();
        int col = grid[0].size();
        for(int i = 0; i <= (grid.size() / 2); i++){
            for(int j = 0; j < grid.size(); j++){
                for(int k = 0; k < grid[0].size(); k++){
                    if(i == 0) pushEle(pq, grid[j][k]);
                    else
                    {
                        int ur = returnUpRight(grid, j, k, i, row, col);
                        int dr = returnDownRight(grid, j - i, k + i, i, row, col);
                        int dl = returnDownLeft(grid, j, k + (i * 2), i, row, col);
                        int ul = returnUpLeft(grid, j + i, k + i, i, row, col);

                        if(ur == -1 || ul == -1 || dr == -1 || dl == -1) break;
                        pushEle(pq, ur + ul + dr + dl);
                    }
                    
                }
            }
        }

        vector<int> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};