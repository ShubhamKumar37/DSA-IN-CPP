#include <IOSTREAM>
#include <VECTOR>

using namespace std;

void findMissingElement1(vector<int> &arr, int length)
{
    int sum = 0;
    int completeSum = ((length * (length + 1)) >> 1);

    for (auto i : arr)
    {
        sum += i;
    }

    cout << "Missing element is " << completeSum - sum << endl;
}

void findMissingElement2(vector<int> &arr, int length)
{
    int finalNum = 0;

    for (int i = 0; i < length; i++)
    {
        finalNum ^= arr[i];
        finalNum ^= i;
    }
    finalNum ^= length;

    cout << "Missing element is " << finalNum << endl;
}

int main()
{
    vector<int> arr = {0, 3, 2, 1, 5};
    int length = arr.size();

    // findMissingElement1(arr, length);
    findMissingElement2(arr, length);

    return 0;
}