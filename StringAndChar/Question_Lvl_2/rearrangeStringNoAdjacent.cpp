#include<IOSTREAM>
#include<STRING>

using namespace std;

string rearrangeStr(string &str)
{
    int charMap[26] = {0};

    for(auto i : str) charMap[i - 'a']++;

    int maxFreqIndex = 0;

    for(int i = 1; i < 26; i++)
    {
        if(charMap[maxFreqIndex] < charMap[i])
        {
            maxFreqIndex = i;
        }
    }

    int index = 0;
    while(index < str.size() && charMap[maxFreqIndex] > 0)
    {
        str[index] = 'a' + maxFreqIndex;
        charMap[maxFreqIndex]--;
        index += 2;
    }

    if(index >= str.size() && charMap[maxFreqIndex] > 0) return "-1";

    for(int i = 0; i < 26; i++)
    {
        while(charMap[i] > 0)
        {
            index = index >= str.size() ? 1 : index;
            str[index] = (char)(i + 'a');
            charMap[i]--;
            index += 2;
        }
    }

    return str;
}

int main()
{
    string str;

    cin >> str;

    cout << "Alternative rearrangment can be =-> " << rearrangeStr(str) << " <-= " << endl;


    return 0;
}