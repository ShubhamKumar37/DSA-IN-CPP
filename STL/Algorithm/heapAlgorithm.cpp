#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int> &arr)
{
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {5, 4, 3, 5, 6, 43, 32, 6, 3, 1, 6};

    // This will create a max heap of vector
    make_heap(arr.begin(), arr.end());

    print(arr);

    arr.push_back(100);
    push_heap(arr.begin(), arr.end());

    print(arr);

    pop_heap(arr.begin(), arr.end());
    print(arr);
    arr.pop_back();
    print(arr);

    sort_heap(arr.begin(), arr.end());
    print(arr);



    return 0;
}