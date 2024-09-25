#include<IOSTREAM>
#include<STRING>

using namespace std;

void Reverse(string &str, int index)
{
    if(index >= (str.size() >> 1)) return ;

    swap(str[index], str[str.size() - index - 1]);

    Reverse(str, index + 1);
}

int main()
{
    string str = "Shubham Kumar";

    Reverse(str, 0);
    cout << "After reversing the string = " << str << endl;


    return 0;
}