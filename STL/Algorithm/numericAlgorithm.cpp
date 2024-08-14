#include <IOSTREAM>
#include <VECTOR>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> first = {1, 2, 3};
    vector<int> second = {4, 5, 6};
    vector<int> ans(arr.size());

    // This is equal to prefix sum array just need to provide the begin() of result vector so mention its size while declaring it
    // partial_sum(arr.begin(), arr.end(), ans.begin());

    // This will just increment the initail value by one where first element will be itself intialValue and this will go till the size of the result array
    iota(ans.begin(), ans.end(), 30);

    for(auto i : ans) cout << i << " ";
    cout << endl;

    // First two argument are the range of first vector and third is starting point of second vector and last is the initial value
    // Works - 1 * 2 + 2 * 5 + 3 * 6 + initalValue
    // make sure the first two arugment vector have larger then equal to second vector
    // int innerProduct = inner_product(first.begin(), first.end(), second.begin(), 0);

    // cout << "Inner product of 2 vector is " << innerProduct << endl;

    // First two will be the range for which we have to find sum and third will be the initial value
    // int totalSum = accumulate(arr.begin(), arr.end(), 10);

    // cout << "Sum of the array is " << totalSum << endl;

    return 0;
}