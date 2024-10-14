#include<IOSTREAM>
#include<STRING>

using namespace std;

// void getPermutation(string str, int index)
// {
//     if(index >= str.size())
//     {
//         cout << str << endl;
//     }

//     for(int i = index; i < str.size(); i++)
//     {
//         swap(str[i], str[index]);
//         // cout << "index =  " << index << " i = " << i << " Value changed to " << str << endl;

//         // Here if we donot backtract using by value call then 
//         // the changed string will going to be passed to recursive call
//         // but the only difference is going to be maked will be the order of the string and nothing else
//         getPermutation(str, index + 1);
//         // swap(str[i], str[index]);
//     }
// }

void getPermutation(string &str, int index)
{
    if(index >= str.size())
    {
        cout << str << endl;
        return ;
    }

    for(int i = index; i < str.size(); i++)
    {
        swap(str[i], str[index]);
        getPermutation(str, index + 1);
        swap(str[i], str[index]);
    }
}

int main()
{
    string str = "abcd";

    getPermutation(str, 0);

    return 0;
}