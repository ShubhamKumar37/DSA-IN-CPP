#include<IOSTREAM>

using namespace std;

int main()
{

    // int a = 5;
    // int b = a;
    // int *c = &a;
    // char ch = 'h';
    // char* chPtr = &ch;
    // long longValue = 1000000;
    // long* longPtr = &longValue;
    // long* longPtr = 0; // This is how we create a null pointer
    // cout << longPtr << endl;

    // cout << a << endl;
    // cout << &a << endl;
    // cout << *a << endl;
    // cout << c << endl;
    // cout << *c << endl;
    // cout << &c << endl; 
    // cout << c << endl;

    // cout << sizeof(c) << endl;
    // cout << sizeof(c) << endl;
    // cout << sizeof(ch) << endl;
    // cout << sizeof(chPtr) << endl;
    // cout << sizeof(longValue) << endl;
    // cout << sizeof(longPtr) << endl;
    // cout << longPtr << endl;
    // cout << *longPtr << endl;

    // When we try to find the size of a pointer it return always as 8;

    // Pointer copy
    int a = 23;
    int *ptr1 = &a;
    int *ptr2 = ptr1;

    cout << &ptr2 << endl;
    *ptr2 = 34;
    cout << *ptr1 << endl;
    cout << *ptr2 << endl;


    return 0;
}
