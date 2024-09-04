#include<IOSTREAM>
#include<STRING>

using namespace std;

string removeAdjecentDuplicate1(string str)
{
    int i = 1; 

    while(i < str.size())
    {
        if(i >= 1 && str[i] == str[i - 1])
        {
            str.erase(i - 1, 2);
            i--;
        }
        else i++;
    }

    return str;
}

string removeAdjecentDuplicate2(string str)
{
    string ans = "";

    for(auto i : str)
    {
        if(ans.empty() || ans.back() != i)
        {
            ans.push_back(i);
        }
        else ans.pop_back();
    }

    return ans;
}

int main()
{
    string str;
    cin >> str;

    // cout << "Final String after removing adjacent duplicate will be " << removeAdjecentDuplicate1(str) << endl;
    cout << "Final String after removing adjacent duplicate will be " << removeAdjecentDuplicate2(str) << endl;
}