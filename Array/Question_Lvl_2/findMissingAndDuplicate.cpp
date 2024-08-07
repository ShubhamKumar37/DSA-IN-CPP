#include<IOSTREAM>

using namespace std;

void findMissingAndDuplicate1(int arr[], int length)
{
    int duplicateElement = 0;

    for(int i = 0; i < length; i++)
    {
        int index = abs(arr[i]) - 1;
        if(arr[index] < 0)
        {
            duplicateElement = index + 1;
        }

        arr[index] = -abs(arr[index]);
    }

    cout << "Duplicate element = " << duplicateElement << endl;
    cout << "Missing Element are :" << endl;
    for(int i = 0; i < length; i++)
    {
        if(arr[i] > 0)
        {
            cout << i + 1 << endl;
        }
    }
}

int main()
{
    int arr[] = {1, 7, 5, 4, 5, 6, 2};
    int length = sizeof(arr) >> 2;

    findMissingAndDuplicate1(arr, length);



    return 0;
}