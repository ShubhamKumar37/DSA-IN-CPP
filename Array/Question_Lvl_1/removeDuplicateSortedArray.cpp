#include <IOSTREAM>
#include <VECTOR>

using namespace std;

void removeDuplicate1(vector<int> arr, int length)
{
    int currNewValue = arr[0];
    int i = 1, j = 1;

    while (j < length)
    {
        if (currNewValue != arr[j])
        {
            currNewValue = arr[j];
            arr[i] = arr[j];
            i++;
        }
        j++;
    }

    cout << "Number of unique elements = " << i << endl;

    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

void removeDuplicate2(vector<int> arr, int length)
{
    vector<int> uniqueElements;
    uniqueElements.push_back(arr[0]);

    for (int i = 1; i < length; i++)
    {
        if (uniqueElements.back() != arr[i])
        {
            uniqueElements.push_back(arr[i]);
        }
    }

    for (int i = 0; i < uniqueElements.size(); i++)
    {
        arr[i] = uniqueElements[i];
    }

    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void removeDuplicate3(vector<int> arr, int length)
{
    int j = 0;

    for (int i = 1; i < length; i++)
    {
        if (arr[i] != arr[j])
        {
            arr[++j] = arr[i];
        }
    }

    cout << "Number of unique elements = " << j + 1 << endl;

    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {1, 1, 1, 1, 2, 3, 4, 4, 4, 5, 6, 7, 8};
    int length = arr.size();

    // removeDuplicate1(arr, length);
    // removeDuplicate2(arr, length);
    removeDuplicate3(arr, length);

    return 0;
}