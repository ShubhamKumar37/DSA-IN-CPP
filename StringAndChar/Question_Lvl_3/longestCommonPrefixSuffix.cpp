#include<IOSTREAM>
#include<STRING>
#include<VECTOR>

using namespace std;

pair<int, int> getCommonCount(string &str, int i, int j)
{
    int count = 0;

    while(j < str.size() && str[i] == str[j])
    {
        i++, j++, count++;
    }

    return {j, count};
}

int getLongestSuffPre(string &str)
{
    int i = 0;
    int j = 1;
    int count = 0;

    while(true)
    {
        pair<int, int> p = getCommonCount(str, i, j);

        if(p.first >= str.size()) 
        {
            count = p.second;
            break;
        }

        j = j + 1;
    }

    return count;
}

int main()
{
    string str = "bbbbcddd";

    cout << "Longest common suffix and prefix = " << getLongestSuffPre(str) << endl;


    return 0;
}