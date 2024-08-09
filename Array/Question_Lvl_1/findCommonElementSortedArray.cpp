#include <IOSTREAM>
#include <VECTOR>

using namespace std;

void findCommonElement1(vector<int> arr1, vector<int> arr2, vector<int> arr3, int length1, int length2, int length3)
{
    for (int i = 0; i < length1; i++)
    {
        for (int j = 0; j < length2; j++)
        {
            for (int k = 0; k < length3; k++)
            {
                if (arr1[i] == arr2[j] && arr2[j] == arr3[k])
                {
                    cout << arr1[i] << " ";
                }
            }
        }
    }

    cout << endl;
}

void findCommonElement2(vector<int> arr1, vector<int> arr2, vector<int> arr3, int length1, int length2, int length3)
{
    int i = 0, j = 0, k = 0;

    while (i < length1 && j < length2 && k < length3)
    {
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k])
        {
            cout << arr1[i] << " ";
            i++, j++, k++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr2[j] < arr3[k])
        {
            j++;
        }
        else
        {
            k++;
        }
    }
}

int main()
{
    vector<int> arr1 = {1, 5, 10, 20, 40, 80};
    vector<int> arr2 = {6, 7, 20, 80, 100};
    vector<int> arr3 = {3, 4, 15, 20, 30, 70, 80, 120};

    findCommonElement1(arr1, arr2, arr3, arr1.size(), arr2.size(), arr3.size());
    findCommonElement2(arr1, arr2, arr3, arr1.size(), arr2.size(), arr3.size());

    return 0;
}