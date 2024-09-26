#include<IOSTREAM>
#include<VECTOR>

using namespace std;

// mainly for printing all the sub array we can use 2 loops where first loop will start from index 0 and second loop will start from index i and j

void printValue(vector<int> &arr, int i, int j)
{

    if(j == arr.size()) return ;

    for(int start = i; start <= j; start++)
    {
        cout << arr[start] << " ";
    } cout << endl;

    printValue(arr, i, j + 1);
}

void printAllSubArray(vector<int> &arr, int index)
{
    for(int i = index; i < arr.size(); i++)
    {
        printValue(arr, i, i);
    }
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 5, 6};


    printAllSubArray(arr, 0);


    return 0;
}