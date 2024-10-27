#include <IOSTREAM>
#include <STRING>
#include <unordered_map>
#include <VECTOR>

using namespace std;

void getCombination(string &digit, string &temp, vector<string> &ans, int index, unordered_map<char, string> &mapStr)
{
    if(index >= digit.size()) 
    {
        ans.push_back(temp);
        return ;
    }

    string currectStr = mapStr[digit[index]];
    for(int i = 0; i < currectStr.size(); i++)
    {
        temp.push_back(currectStr[i]);
        getCombination(digit, temp, ans, index + 1, mapStr);
        temp.pop_back();
    }
}

int main()
{
    unordered_map<char, string> mapStr = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    vector<string> ans;
    string temp = "";
    string digit;

    cin >> digit ;

    getCombination(digit, temp, ans, 0, mapStr);

    cout << "-----Printing the result-----" << endl;

    for(auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}