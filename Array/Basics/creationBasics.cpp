#include<IOSTREAM>

using namespace std;

int main()
{

    int arr1[3] = {1, 2};
    int arr2[] = {1, 232};
    int arr3[5] = {1, 2};

    cout << arr1[2] << endl;
    cout << arr2[3] << endl;
    cout << arr3[3] << endl;
    cout << arr1 << endl;

    fill(arr3, arr3 + 5, 92);

    for(int i = 0; i < 5; i++)
    {
        cout << "Enter value of index " << i + 1 << " = ";
        cin >> arr3[i];
    }
    cout << endl;

    for(int i = 0; i < 5; i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl;


    return 0;
}