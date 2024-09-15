#include<IOSTREAM>
#include<STRING>

using namespace std;

void reverse(string &str, int i, int j)
{
    while(i < j)
    {
        swap(str[i++], str[j--]);
    }
}

int compressString(string &str)
{
    int index = 0;
    
    for(int i = 0; i < str.size(); )
    {
        int j = i;
        int count = 0;

        while(j < str.size() && str[j] == str[i])
        {
            count++;j++;
        }

        str[index++] = str[i];

        if(count > 1)
        {
            while(count != 0)
            {
                str[index++] = (count % 10) + '0';
                count /= 10;
            }
            reverse(str, i + 1, index - 1);
        }

        i = j;
    }

    return index;
}

int main()
{
    string str;
    cin >> str;


    cout << "After compression string will be = " << str.substr(0, compressString(str));

    return 0;
}