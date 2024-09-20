#include<IOSTREAM>
#include<VECTOR>
#include<STRING>

using namespace std;

void makeSubSequence(string &str, vector<string> &ans, int index, string temp)
{
    if(index == str.size()) 
    {
        ans.push_back(temp);
        return ;
    }

    makeSubSequence(str, ans, index + 1, temp);
    makeSubSequence(str, ans, index + 1, temp + str[index]);
}

void printSubSequence(string &str, int index, string temp)
{
    if(index == str.size())
    {
        if(temp.size() == 0) cout << "' ', ";
        else cout << temp << ", ";
        return ;
    }

    printSubSequence(str, index + 1, temp);
    printSubSequence(str, index + 1, temp + str[index]);
}

int main()
{
    string str = "aaaab";

    printSubSequence(str, 0, "");
    // vector<string> ans;

    // makeSubSequence(str, ans, 0, "");

    // for(auto i : ans)
    // {
    //     if(i.size() == 0) cout << "' ', ";
    //     else cout << i << ", ";
    // }
    // cout << endl;


    return 0;
}