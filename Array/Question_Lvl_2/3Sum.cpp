#include<IOSTREAM>
#include<set>
#include<VECTOR>
#include<algorithm>

using namespace std;

void getPossible(vector<int> &arr, set<vector<int>> &set, int index)
{
    int s = index + 1;
    int e = arr.size() - 1;

    while(s < e)
    {
        int sum = arr[index] + arr[s] + arr[e];

        if(sum == 0)
        {
            vector<int> temp = {arr[index], arr[s], arr[e]};
            set.insert(temp);
            s++, e--;
        }
        else if(sum < 0) s++;
        else e--;
    }
}

void getAllTriplet(vector<int> &arr, set<vector<int>> &s)
{
    for(int i = 0; i < arr.size() - 2; i++)
    {
        getPossible(arr, s, i);
    }
}

int main()
{ 
    vector<int> arr = {3,0,-2,-1,1,2};
    vector<vector<int> > ans;
    set<vector<int>> s;
    
    sort(arr.begin(), arr.end());

    getAllTriplet(arr, s);

    for(auto i : s) ans.push_back(i);

    cout << "===== Here all the triplet =====" << endl;
    for(auto i : ans)
    {
        for(auto j : i)   
        {
            cout << j << " ";
        }
        cout << endl;
    }


    return 0;
}