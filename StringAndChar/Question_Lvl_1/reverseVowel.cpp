#include<IOSTREAM>
#include<STRING>

using namespace std;

bool isVowel(char &ch)
{
    char arr[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    for(auto i : arr)
    {
        if(ch == i) return true;
    }

    return false;
}

string reverseVowel(string str)
{
    int i = 0;
    int j = str.size() - 1;

    while(i < j)
    {
        if(!isVowel(str[i])) i++;
        else if(!isVowel(str[j])) j--;
        else swap(str[i++], str[j--]);
    }

    return str;
}


int main()
{
    string str;
    cin >> str;

    cout << "After reversing only vowels " << reverseVowel(str) << endl;

    return 0;
}
