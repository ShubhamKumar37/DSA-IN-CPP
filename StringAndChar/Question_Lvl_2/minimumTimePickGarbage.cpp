#include<IOSTREAM>
#include<VECTOR>
#include<STRING>
#include<MAP>
#include<algorithm>

using namespace std;


void findLastOccurance(vector<string> &garbage, unordered_map<char, int> &map)
{
    for(int i = garbage.size() - 1; i >= 0; i--)
    {
        for(auto j : garbage[i])
        {
            if(map.size() == 3) return ;
            else if(map.find(j) == map.end()) map[j] = i;
        }
    }
}
int findMinTime(vector<string> &garbage, vector<int> &time)
{
    int ans = 0;

    unordered_map<char, int> map;
    findLastOccurance(garbage, map);

    for(int i = 1; i < time.size(); i++) time[i] += time[i - 1];

    for(auto i : map)
    {
        for(int j = 0; j <= i.second; j++) ans += count(garbage[j].begin(), garbage[j].end(), i.first);

        ans += i.second - 1 < 0 ? 0 : time[i.second - 1];
    }

    return ans;
}

int main()
{ 
    vector<string> v;
    vector<int> t;
    int n ;
    cout << "Enter the size then give the garbage status and then the travel time :-  " << endl;
    cin >> n; 
    

    for(int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        v.push_back(temp);
    }

    for(int i = 0; i < n - 1; i++)
    {
        int temp;
        cin >> temp;
        t.push_back(temp);
    }


    cout << "Minimum time required to pick all the garbage = " << findMinTime(v, t) << endl;


    return 0;
}