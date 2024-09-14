#include<IOSTREAM>
#include<STRING>

using namespace std;

int findFirstOccurance(string &str1, string &str2)
{
    auto it = str1.find(str2);

    if(it == string::npos) return -1;

    return it;
}

int main()
{

    string str1, str2; 

    cin >> str1 >> str2;

    cout << "First occurance index of string is " << findFirstOccurance(str1, str2) << endl;


    return 0;
}