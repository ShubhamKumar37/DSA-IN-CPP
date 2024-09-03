#include<IOSTREAM>

using namespace std; 

int main()
{
    string str = "Shubham Kumar";

    // cout << "Enter your name = ";
    // cin >> str;

    // for(;;)
    // {
    //     char val;
    //     cin.get(val);

    //     if(val == '1') break;
    //     str.push_back(val);
    // }

    cout << "Your name is " << str << endl;
    cout << str.substr(0) << endl;
    cout << str.substr(0, 3) << endl;
    cout << str.substr(3, 3) << endl;
    cout << str.substr(3, 30) << endl;
    cout << str.find("am") << endl;
    cout << str.find("nam3") << endl;

    if(str.find("nam2") == string::npos)
    {
        cout << "String not found in " << str << endl;
    }



    return 0;
}