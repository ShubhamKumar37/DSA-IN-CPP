#include<IOSTREAM>
#include<STRING.H>

using namespace std;

int findLastOccurance(string str, int index, char target)
{
    if(index == str.size()) return -1;

    int ans = -1;
    if(str[index] == target)
    {
        ans = index;
    }
    int newAns = findLastOccurance(str, index + 1, target);

    return newAns == -1 ? ans : newAns;
    
}

int main()
{
    string str = "My name is shubham kumar";
    char target = 'p';

    cout << "Last occurance of the char is " << findLastOccurance(str, 0, target) << endl;


    return 0;
}