#include <IOSTREAM>
#include <VECTOR>
#include <algorithm>

using namespace std;

void setDouble(int &a)
{
    cout << a * 2 << " ";
    a *= 2;
}

bool ifEven(int &num)
{
    // return num % 2 == 0;
    return (num & 1) == 0;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // vector<int> arr = {1, 2, 3, 4, 5, 6, 2, 4, 2, 5, 6, 3, 6, 3, 2, 54};

    // sort(arr.begin(), arr.end());

    for (auto i : arr)
        cout << i << " ";
    cout << endl;

    // Left side will be those who follow the function and vice versa
    auto it = partition(arr.begin(), arr.end(), ifEven);

    // auto it = unique(arr.begin(), arr.end());
    // arr.erase(it, arr.end());

    // First argumenti is the place where we want to move the element,
    // Second argument is the element we want to move at the begin.
    // Third argument is the range for which our iterator perform the first two operation. (May be)
    // rotate(arr.begin(), arr.end() - 2, arr.end());
    // rotate(arr.begin(), arr.begin() + 2, arr.end());

    for (auto i : arr)
        cout << i << " ";
    cout << endl;

    // reverse(arr.begin(), arr.end());
    // auto target = 50;
    // auto Count = count(arr.begin(), arr.end(), target);
    // auto Count = count_if(arr.begin(), arr.end(), ifEven);

    // cout << "Number of " << target << " in array is " << Count << endl;
    // cout << "Number of even element in array is " << Count << endl;

    // First two arguments are the range and third one is the function from which iterator will decide to return the the itrator or not and this will only return the first element found in array
    // auto it = find_if(arr.begin(), arr.end(), ifEven);

    // cout << (!*it ? "Element is founded " : "Element not found ") << endl;
    // cout << *it << endl;

    // This will help to apply operation on whole array which is decided on the third parameter
    // for_each(arr.begin(), arr.end(), setDouble);
    // cout << endl;

    // auto it = find(arr.begin(), arr.end(), 14);

    // if(!*it)
    // {
    //     cout << "Element is not found " << endl;
    // }
    // else{
    //     cout << "Element is founded " << endl;
    // }

    // for(auto i : arr)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    return 0;
}