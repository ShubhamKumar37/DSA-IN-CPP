#include<IOSTREAM>

using namespace std;

int findElement(int arr[], int length, int target)
{
    for(int i = 0; i < length; i++)
    {
        if(arr[i] == target)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {4, 5, 2, 5, 3, 8, 6, 9};
    int length = sizeof(arr) / sizeof(int);
    int target = 50;

    int indexElement = findElement(arr, length, target);

    if(indexElement != -1)
    {
        cout << "Target found at index = " << indexElement << endl;
    }
    else
    {
        cout << "Target is not found" << endl;
    }

    return 0;
}