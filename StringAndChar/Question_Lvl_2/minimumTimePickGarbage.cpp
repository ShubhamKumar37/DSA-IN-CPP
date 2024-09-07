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

void findOccurance(vector<string> &garbage, vector<int> &PGM, unordered_map<char, int> &map)
{
    for(int i = 0; i < garbage.size(); i++)
    {
        for(auto j : garbage[i]){
            if(j == 'P') PGM[0]++;
            else if(j == 'G') PGM[1]++;
            else if(j == 'M') PGM[2]++;

            map[j] = i;
        }
    }
}

int findMinTime2(vector<string> &garbage, vector<int> &time)
{ 
    int ans = 0;
    vector<int> PGM(3, 0);
    unordered_map<char, int> map;

    findOccurance(garbage, PGM, map);

    for(int i = 1; i < time.size(); i++) time[i] += time[i - 1];

    for(auto i : map)
    {
        int travel = i.second - 1 < 0 ? 0 : time[i.second - 1];
        
        if(i.first == 'P') ans += PGM[0] + travel;
        else if(i.first == 'G') ans += PGM[1] + travel;
        else if(i.first == 'M') ans += PGM[2] + travel;
    }

    return ans;
}

int findMinTime1(vector<string> &garbage, vector<int> &time)
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


    // cout << "Minimum time required to pick all the garbage = " << findMinTime1(v, t) << endl;
    cout << "Minimum time required to pick all the garbage = " << findMinTime2(v, t) << endl;


    return 0;
}