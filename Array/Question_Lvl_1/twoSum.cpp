#include<IOSTREAM>

using namespace std;

void print2Sum(int arr[], int length, int target)
{
    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < length; j++)
        {
            if(arr[i] + arr[j] == target)
            {
                cout << arr[i] << " + " << arr[j] << " = " << target << endl;
            }
        }
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int target = 30;
    int length = sizeof(arr)/sizeof(arr[0]);

    cout << "All pair with target sum is written below" << endl;
    print2Sum(arr, length, target);

    return 0;
}