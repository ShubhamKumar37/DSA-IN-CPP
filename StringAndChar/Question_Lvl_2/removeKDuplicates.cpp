#include<IOSTREAM>
#include<STRING>

using namespace std;

bool checkDuplicate(string &temp, int k, char &target)
{
    for(int i = (temp.size() - 1); i >= (temp.size() - k) && i >= 0; i--)
    {
        if(temp[i] != target) return false;
    }
    return true;
}

string removeDuplicate(string &s, int k)
{
    string temp = "";

    for(int i = 0; i < s.size(); i++)
    {
        if(temp.size() >= (k - 1))
        {
            if(checkDuplicate(temp, k - 1, s[i]))
            {
                for(int j = 0; j < (k - 1); j++) temp.pop_back();
            }
            else temp += s[i];
        }
        else temp += s[i];
    }

    return temp;
}

int main()
{
    string s = "nnwssswwnvbnnnbbqhhbbbhmmmlllm";
    int k = 3;

    cout << "After changing the string = " << removeDuplicate(s, k) << endl;

    return 0;
}