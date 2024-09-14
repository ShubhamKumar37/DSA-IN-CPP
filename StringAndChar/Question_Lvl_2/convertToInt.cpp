#include<IOSTREAM>
#include<LIMITS>
#include<STRING>
#include<algorithm>

using namespace std;

int convertString(string &str)
{
    int i = 0;
    int isSign = 1;
    int ans = 0;

    while(i < str.size() && str[i] == ' ') ++i;

    if(i < str.size() && (str[i] == '+' || str[i] == '-'))
    {
        isSign = str[i++] == '-' ? -1 : 1;
    }

    while (i < str.size() && isdigit(str[i]))
    {
        int temp = str[i++] - '0';

        if(ans > INT_MAX / 10 || (ans == INT_MAX / 10 && temp > 7))
        {
            return isSign == 1 ? INT_MAX : INT_MIN;
        }

        ans = ans * 10 + temp;
    }

    return ans * isSign;
    
}

int main()
{
    string str;
    cin >> str;

    cout << "Converted integer is " << convertString(str) << endl;



    return 0;
}