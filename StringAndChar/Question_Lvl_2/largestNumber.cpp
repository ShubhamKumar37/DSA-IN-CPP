#include<IOSTREAM>
#include<STRING>
#include<VECTOR>
#include<string>
#include<algorithm>

using namespace std;

bool cmp(string& a, string& b)
{
    return (a + b) > (b + a);
}

string makeLargest(vector<int> &arr)
{
    vector<string> str;
    string ans = "";

    for(auto i : arr)
    {
        str.push_back(to_string(i));
    }

    sort(str.begin(), str.end(), cmp);

    for(auto i : str)
    {
        ans += i;
    }

    return ans;
    
}

int main()
{
    vector<int> arr = {43, 5, 2, 42};

    cout << "Larget number that can be created is " << makeLargest(arr) << endl;


    return 0;
}