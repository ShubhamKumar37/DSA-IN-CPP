#include<IOSTREAM>

using namespace std;

int main()
{
    int arr[5];

    for(int i = 0; i < 5; i++)
    {
        cout << "Enter the " << i <<" th value = ";
        cin >> arr[i];
    }
    for(int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // This work because in backend it is display like *(arr + i * sizeof declared datatype) due to which
    // arr[i] === *(arr + i)
    // i[arr] === *(i + arr)
    for(int i = 0; i < 5; i++)
    {
        cout << i[arr] << " ";
    }

    

}