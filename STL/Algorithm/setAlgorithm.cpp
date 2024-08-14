#include <IOSTREAM>
#include <VECTOR>
#include <algorithm>

using namespace std;

void print(vector<int> arr)
{
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> first = {1, 2, 3, 4, 5};
    vector<int> second = {3, 4, 5, 6, 7, 8, 9};
    vector<int> result;

    // set_intersection(first.begin(), first.end(), second.begin(), second.end(), inserter(result, result.begin()));
    // set_union(first.begin(), first.end(), second.begin(), second.end(), inserter(result, result.begin()));
    // set_difference(first.begin(), first.end(), second.begin(), second.end(), inserter(result, result.begin()));

    // This will return the Union - Intersection of both vector
    set_symmetric_difference(first.begin(), first.end(), second.begin(), second.end(), inserter(result, result.begin()));

    print(result);

    return 0;
}