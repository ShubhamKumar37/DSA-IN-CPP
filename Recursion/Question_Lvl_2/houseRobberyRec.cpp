#include<IOSTREAM>
#include<VECTOR>

using namespace std;

int maxProfit(vector<int> &arr, int index)
{
    if(index >= arr.size()) return 0;

    int include = arr[index] + maxProfit(arr, index + 2);
    int exclude = maxProfit(arr, index + 1);

    return include > exclude ? include : exclude;
}

int main()
{
    vector<int> arr = {4, 3, 2, 5, 4};

    cout << "Maximum profit can be generated if two adjacent house are robbed = " << maxProfit(arr, 0) << endl;


    return 0;
}