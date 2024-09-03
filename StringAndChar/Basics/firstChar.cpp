#include <IOSTREAM>

using namespace std;

int findLength(char arr[])
{
    int count = 0;
    while (arr[count] != '\0')
        count++;

    return count;
}

void replaceValue(char arr[], char replaceValue)
{
    int i = 0;

    while (arr[i] != '\0')
    {
        if (arr[i] == '@')
        {
            arr[i] = replaceValue;
        }
        i++;
    }
}

void changeCase(char arr[])
{
    int i = 0;
    while(arr[i] != '\0')
    {
        if(arr[i] >= 'a' && arr[i] <= 'z')
        {
            arr[i] = arr[i] - 'a' + 'A';
        }
        else if(arr[i] >= 'A' && arr[i] <= 'Z')
        {
            arr[i] = arr[i] - 'A' + 'a';
        }
        i++;
    }
}

void reverseArray(char arr[])
{
    int length = findLength(arr);

    for(int i = 0; i < (length >> 1); i++)
    {
        swap(arr[i], arr[length - i - 1]);
    }
}

bool isPalindrome(char arr[])
{
    int length = findLength(arr);

    for(int i = 0; i < (length >> 1); i++) if(arr[i] != arr[length - i - 1])  return false;

    return true;
}

int main()
{
    char arr[100];

    cout << "Enter your name = ";
    // cin >> arr;
    cin.getline(arr, 100);

    // Third parameter is delimeter which mean when any input encounter this value it will stop taking input and get to next line.

    // cin.getline(arr, 100, '\n');
    // cin.getline(arr, 100, 'm');

    cout << "Your name is " << arr << endl;
    cout << "Length of the char array is " << findLength(arr) << endl;
    // replaceValue(arr, ' ');
    // changeCase(arr);
    reverseArray(arr);
    cout << "Your edited char array is " << arr << endl;


    cout << "Your palindrome status is " << isPalindrome(arr) << endl;

    // cout << arr[7] << " -> " << (int)arr[7] << endl;
    // cout << arr[8] << " -> " << (int)arr[8] << endl;
    // cout << arr[9] << " -> " << (int)arr[9] << endl;
    // cout << arr[15] << " -> " << (int)arr[15] << endl;

    // for(int i = 0; i < 30; i++)
    // {
    //     cout << arr[i] << " -> " << (int)arr[i] << endl;
    // }

    return 0;
}