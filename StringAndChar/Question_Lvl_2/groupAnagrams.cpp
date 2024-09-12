#include<IOSTREAM>
#include<STRING>
#include<VECTOR>
#include<MAP>
#include<algorithm>

using namespace std;

vector<vector<string>> getGroupAnagram1(vector<string> arr)
{
    unordered_map<string, vector<string>> Map;
    vector<vector<string>> ans;

    for(auto i : arr)
    {
        string temp = i;
        sort(temp.begin(), temp.end());

        Map[temp].push_back(i);
    }

    for(auto i : Map) ans.push_back(i.second);


    return ans;
}


std::array<int, 256> getHash(string str)
{
    std::array<int, 256> hash = {0};

    for(auto i : str) hash[(int)i]++;

    return hash;
}

vector<vector<string>> getGroupAnagram2(vector<string> &arr)
{
    map<std::array<int, 256>, vector<string>> Map;
    vector<vector<string>> ans;

    for(auto i : arr)
    {
        std::array<int, 256> hash = getHash(i);

        Map[hash].push_back(i);
    }

    for(auto i : Map) ans.push_back(i.second);
    return ans;
}

int main()
{
    int n;
    
    cout << "Enter the length of array = ";
    cin >> n;

    vector<string> arr;

    for(int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        arr.push_back(temp);
    }

    // vector<vector<string>> ans = getGroupAnagram1(arr);
    vector<vector<string>> ans = getGroupAnagram2(arr);

    cout << "After grouping anagram of the array :" << endl;

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