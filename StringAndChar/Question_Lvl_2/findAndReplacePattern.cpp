#include <IOSTREAM>
#include <VECTOR>
#include <STRING>
#include <unordered_map>

using namespace std;

string makePattern(string str)
{
    int n = str.size();
    unordered_map<char, char> map;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (map.find(str[i]) == map.end())
        {
            map[str[i]] = (char)(count++ + 'a');
        }
        str[i] = map[str[i]];
    }

    return str;
}

vector<string> findPatternString(vector<string> &words, string &pattern, int n)
{
    int count = 0;
    vector<string> ans;
    vector<string> newWords(n);

    pattern = makePattern(pattern);
    for (int i = 0; i < n; i++)
    {
        newWords[i] = makePattern(words[i]);
        
        if(pattern == newWords[i]) ans.push_back(words[i]);
    }

    return ans;
}

int main()
{
    vector<string> words;
    string pattern;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        words.push_back(temp);
    }

    cin >> pattern;

    vector<string> replacedStrings = findPatternString(words, pattern, n);

    cout << "These are the string which follow the pattern :- " << endl;
    for (auto i : replacedStrings)
    {
        cout << i << " ";
    }

    return 0;
}