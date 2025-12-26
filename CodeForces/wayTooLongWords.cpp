#include<iostream>
#include<string>
#include<vector>

using namespace std;

string compressString(string &str)
{
    if(str.size() <= 10) return str;
    int n = str.size();
    
    return str[0] + to_string(n - 2) + str[n - 1];
}

int main()
{
    int n;
    vector<string> arr;

    cin>>n;

    for(int i = 0; i < n; i++)
    {
        string str;
        cin>>str;
        arr.push_back(str);
    }
    for(auto i : arr) cout << compressString(i) << endl;

    return 0;
}