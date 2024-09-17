#include <IOSTREAM>

using namespace std;

int main()
{

    // int arr[5] = {1, 2, 3, 4, 5};
    // int *ptr = arr;
    // cout << ptr << endl;
    // cout << *ptr << endl;
    // cout << *(ptr + 0) << endl;
    // cout << *(ptr + 1) << endl;
    // cout << *(ptr + 2) << endl;
    // cout << *(ptr + 3) << endl;
    // cout << *(ptr + 4) << endl;
    // cout << endl;

    // int arr2[5] = {1, 2, 3, 4, 5};
    // int *ptr2 = arr2;
    // ptr2++;
    // cout << *ptr2 << endl;
    // ptr2--;
    // cout << *ptr2 << endl;
    // ptr2 += 2;
    // cout << *ptr2 << endl;
    // ptr2 -= 2;
    // cout << *ptr2 << endl;
    // cout << endl;

    // int arr3[5] = {1, 2, 3, 4, 5};
    // int *ptr3 = arr3;
    // ptr3 = ptr3 + 2;
    // cout << *ptr3 << endl;
    // ptr3 = ptr3 - 1;
    // cout << *ptr3 << endl;
    // ptr3 = ptr3 + 1;
    // cout << *ptr3 << endl;
    // cout << endl;

    // int arr4[5] = {1, 2, 3, 4, 5};
    // int *ptr4 = arr4;
    // ptr4 = ptr4 + 3;
    // cout << *ptr4 << endl;
    // ptr4 = ptr4 - 2;
    // cout << *ptr4 << endl;
    // ptr4 = ptr4 + 1;
    // cout << *ptr4 << endl;
    // cout << endl;

    // int arr5[5] = {1, 2, 3, 4, 5};
    // int *ptr5 = arr5;
    // ptr5 = ptr5 + 4;
    // cout << *ptr5 << endl;
    // ptr5 = ptr5 - 3;
    // cout << *ptr5 << endl;
    // ptr5 = ptr5 + 28;
    // cout << *ptr5 << endl;
    // cout << endl;

    // int arr6[5] = {1, 2, 3, 4, 5};
    // arr6 = arr6 + 1;
    // cout << &arr6 << endl;
    // cout << arr6 << endl;
    // int *ptr6 = arr6;
    // cout << *ptr6 << endl;
    // ptr6 = ptr6 + 4;
    // cout << *ptr6 << endl;
    // ptr6 = ptr6 - 2;
    // cout << *ptr6 << endl;
    // ptr6 = ptr6 + 1;
    // cout << *ptr6 << endl;
    // cout << endl;

    int arr7[5] = {1, 2, 3, 4, 5};
    int *ptr7 = arr7;
    int **ptr8 = &ptr7;
    // cout << **ptr8 << endl;
    // ptr8 = ptr8 + 1;
    // cout << **ptr8 << endl; // This lead to segmentation fault

    // Character array have different behaviour with pointers
    char ch = 'a';
    char* cptr = &ch;
    cout << cptr << endl; // Garbage value as it will print until '\0' is not encountered

    return 0;
}