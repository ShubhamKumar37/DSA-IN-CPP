#include <iostream>
#include <vector>
#include <string>

using namespace std;

string isLie(vector<int> &arr, int n)
{
    int count = 0;
    int count1 = arr[0];
    for(int i = 1; i < n; i++)
    {
        if(arr[i] == 1 || arr[i - 1] == 1) count++;
        if(arr[i] == 1) count1++;
    }

    if(count1 == n) return "Yes";
    return count == (n - 1) ? "NO" : "Yes";
}

int main()
{
    int t;
    cin >> t;

    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n; 
        vector<int> arr;
        for(int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }

        cout << isLie(arr, n) << endl;
    }
    return 0;
}