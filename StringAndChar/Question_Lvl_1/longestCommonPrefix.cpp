#include<IOSTREAM>
#include<VECTOR>
#include<STRING>

using namespace std;

bool isCommon(vector<string> &arr, char &ch, int &index)
{
    for(auto i : arr)
    {
        if(index >= i.size() || i[index] != ch) return false;
    }

    return true;
}

string longestCommonPrefix(vector<string> arr, int n)
{
    int minLength = arr[0].size();
    string ans = "";

    for(int i = 0; i < n; i++)
    {
        char ch = arr[0][i];
        if(isCommon(arr, ch, i)) ans.push_back(ch);
        else break;
    }

    return ans;
}

int main()
{
    vector<string> arr;
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        arr.push_back(temp);
    }


    cout << "The longest common prefix = " << longestCommonPrefix(arr, n) << endl;


    return 0;
}