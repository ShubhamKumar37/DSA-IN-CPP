#include <iostream>
#include <vector>

using namespace std;

void findSolution(vector<int> &arr, int n)
{
    int count = 0;
    int count1 = arr[0];
    for(int i = 1; i < arr.size(); i++)
    {
        if(arr[i] == 1 || arr[i - 1] == 1) count++;
        if(arr[i] == 1) count1++;
    }

    if(count == n - 1 && count1 != n) cout << "NO" << endl;
    else cout << "Yes" << endl;
}

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        vector<int> arr;
        int len;
        cin >> len;
        for(int j = 0; j < len; j++)
        {
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }

        findSolution(arr, len);
    }

    return 0;
}