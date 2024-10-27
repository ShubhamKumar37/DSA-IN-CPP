#include<IOSTREAM>
#include<VECTOR>

using namespace std;

int findMaxProfit1(vector<int> arr)
{
    int maxProfit = 0;
    int minPrice = INT_MAX;

    for(int i = 0; i < arr.size(); i++)
    {
        minPrice = min(minPrice, arr[i]);
        maxProfit = max(maxProfit, arr[i] - minPrice);
    }

    return maxProfit;
}

void findMaxProfit2(vector<int> arr, int index, int &maxProfit, int &minPrice)
{
    if(index == arr.size()) return ;

    minPrice = min(minPrice, arr[index]);
    maxProfit = max(maxProfit, arr[index] - minPrice);
    findMaxProfit2(arr, index + 1, maxProfit, minPrice);
}

int main()
{

    vector<int> arr = {7, 1, 5, 3, 6, 4};
    int maxProfit = 0;
    int minPrice = INT_MAX;

    // cout << findMaxProfit1(arr) << endl;
    findMaxProfit2(arr, 0, maxProfit, minPrice);
    cout << maxProfit << endl;


    return 0;
}