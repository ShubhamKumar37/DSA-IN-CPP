#include <IOSTREAM>
#include <STRING>

using namespace std;

bool validAnagram1(string &a, string &b)
{
    if(a.size() != b.size()) return false;

    int arr1[26] = {0};
    int arr2[26] = {0};

    for(int i = 0; i < a.size(); i++)
    {
        int index = a[i] - 'a';
        arr1[index]++;

        index = b[i] - 'a';
        arr2[index]++;
    }

    for(int i = 0; i < 26; i++)
    {
        if(arr1[i] != arr2[i]) return false;
    }

    return true;
}

bool validAnagram2(string &a, string &b)
{
    if(a.size() != b.size()) return false;

    int arr[26] = {0};

    for(int i = 0; i < a.size(); i++)
    {
        int index = a[i] - 'a';
        arr[index]++;
    }

    for(auto i : b)
    {
        int index = i - 'a';
        arr[index]--;
    }

    for(int i = 0; i < 26; i++) if(arr[i] != 0) return false;

    return true;
}

int main()
{
    string a, b;

    cin >> a >> b;

    // if (validAnagram1(a, b))
    if (validAnagram2(a, b))
    {
        cout << "Both string are anagram" << endl;
    }
    else
    {
        cout << "Not an anagram" << endl;
    }

    return 0;
}