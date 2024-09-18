#include <IOSTREAM>
#include <VECTOR>
#include <STRING>

using namespace std;

void makePattern(string &s, int &rows, vector<string> &matrix, int &index)
{
    for (int i = 0; i < rows && index < s.size(); i++, index++)
    {
        matrix[i].push_back(s[index]);
    }

    for (int i = rows - 2; i >= 1 && index < s.size(); i--, index++)
    {
        matrix[i].push_back(s[index]);
    }
}

string makeZigZag(string s, int n)
{
    if(n == 1 || s.size() <= n) return s;

    string ans = "";
    vector<string> matrix(n);
    int i = 0;

    while (i < s.size())
    {
        makePattern(s, n, matrix, i);
    }

    for (auto i : matrix)
    {
        ans += i;
    }

    return ans;
}

int main()
{
    int n;
    cout << "Enter the number of rows = ";
    cin >> n;

    string s;
    cout << "Enter the string = ";
    cin >> s;

    cout << "Zig-Zag string is " << makeZigZag(s, n) << endl;

    return 0;
}