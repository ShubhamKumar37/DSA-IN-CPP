#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

string decodeMessage(string key, string message)
{
    int j = 0;
    string ans = "";
    unordered_map<char, char> map;

    for(int i = 0; i < key.size(); i++)
    {
        if(key[i] == ' ') continue;

        char ch = 'a' + j;
        if(map.find(key[i]) == map.end())
        {
            map[key[i]] = ch;
            j++; 
        }
    }

    for(auto i : message)
    {
        if(i == ' ') ans += i;
        else ans += map[i];
    }

    return ans;
}

int main()
{
    string key;
    string message;

    getline(cin, key);
    getline(cin, message);

    cout << "The decoded message = " << decodeMessage(key, message) << endl;


    return 0;
}