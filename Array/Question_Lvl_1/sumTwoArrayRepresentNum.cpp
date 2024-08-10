#include<IOSTREAM>
#include<VECTOR>
#include<algorithm>

using namespace std;

string calcSum(vector<int> &arr1, vector<int> &arr2)
{
    string ans;
    int carry = 0;
    int i = arr1.size() - 1;
    int j = arr2.size() - 1;

    while(i >= 0)
    {
        int temp = 0;

        if(j >= 0)
        {
            temp += arr2[j];
        }

        temp += arr1[i] + carry;
        carry = temp / 10;
        ans += '0' + (temp % 10);

        j--, i--;
    }

    if(carry != 0)
    {
        ans += '0' + carry;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> arr1;
    vector<int> arr2;

    while(true)
    {
        int temp;
        cin >> temp;
        if(temp == -1)
        {
            break;
        }
        arr1.push_back(temp);
    }
    while(true)
    {
        int temp;
        cin >> temp;
        if(temp == -1)
        {
            break;
        }
        arr2.push_back(temp);
    }

    if(arr1.size() >= arr2.size())
    {
        cout << "The sum of these number is " << calcSum(arr1, arr2) << endl;
    }
    else
    {
        cout << "The sum of these number is " << calcSum(arr2, arr1) << endl;
    }

    return 0;
}