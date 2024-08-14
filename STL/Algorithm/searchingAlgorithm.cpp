#include <IOSTREAM>
#include <VECTOR>
#include <algorithm>

using namespace std;

int main()
{
    // vector<int> arr = {1, 2, 3, 4, 5, 6, 6, 6, 6, 6, 6, 7, 8, 9};
    vector<int> arr = {5, 4, 6, 5, 7, 6, 3, 2, 6, 4, 5, 7, INT_MIN};

    cout << *(min_element(arr.begin(), arr.end())) << endl;
    cout << *(max_element(arr.begin(), arr.end())) << __EDG_CONSTEXPR_ENABLED__;

    // To use this the array should be in sorted manner else it will result wrong answer
    // bool it = binary_search(arr.begin(), arr.end(), 38);

    // lower bond = first element itself or the first greater then equal to element from target
    // auto it = lower_bound(arr.begin(), arr.end(), 00);

    // upper bound = first element which is greater then target
    // auto it = upper_bound(arr.begin(), arr.end(), 9 );

    // auto it = equal_range(arr.begin(), arr.end(), 2);

    // if (it.first != it.second)
    // {
    //     while (it.first != it.second)
    //     {
    //         cout << *(it.first++) << " ";
    //     }
    //     cout << endl;
    // }
    // else
    // {
    //     cout << "Element not found " << endl;
    // }

    return 0;
}