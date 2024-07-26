#include<IOSTREAM>

using namespace std;

void extremePrint(int arr[], int length)
{
    int i = 0, j = length - 1;

    cout << "Below array is extreme pattern traversal " << endl;
    while(i <= j)
    {
        if(i <= j)
        {
            cout << arr[i++] << " ";
        }
        if(i < j)
        {
            cout << arr[j--] << " ";
        }
    }
    cout << endl;
}

int main()
{
    int arr[] = {4, 5, 2, 5, 3, 8, 6, 9, 12};
    int length = sizeof(arr) / sizeof(int);

    extremePrint(arr, length);


    return 0;
}