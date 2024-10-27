#include<IOSTREAM>
#include<VECTOR>

using namespace std;

int findPossible(vector<int> &arr, int index)
{
    if(index >= arr.size())
    {
        return 1;
    }

    int ans = 0;
    for(int i = index; i < arr.size(); i++)
    {
        swap(arr[index], arr[i]);
        if(((index + 1) % arr[index] == 0) || (arr[index] % (index + 1) == 0)) 
        {
            ans += findPossible(arr, index + 1);
        }
        swap(arr[index], arr[i]);
    }

    return ans; 
}

int findPossible2(vector<int> &arr, int currNum)
{
    if(currNum == arr.size()) return 1;

    int ans = 0;
    for(int i = 1; i < arr.size(); i++)
    {
        if(arr[i] == 0 && (i % currNum == 0 || currNum % i == 0))
        {
            arr[i] = currNum;
            ans += findPossible2(arr, currNum + 1);
            arr[i] = 0;
        }
    }
    
    return ans;
}

int main()
{
    int n = 15;

    vector<int> arr(n + 1);
    // vector<int> arr;
    // for(int i = 1; i <= n; i++) arr.push_back(i);

    // cout << "Number of beautiful arrangment = " << findPossible1(arr, 0) << endl;
    cout << "Number of beautiful arrangment = " << findPossible2(arr, 1) << endl;


    return 0;
}