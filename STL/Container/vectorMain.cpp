#include<IOSTREAM>
#include<VECTOR>

using namespace std;
 
int main()
{
    vector<int> arr1; // This refers to creating a container with 0 size

    arr1.push_back(10);

    cout << arr1[4] << endl;
    cout << arr1.capacity() << endl;
    // arr1.push_back(20);
    // arr1.push_back(30);
    // arr1.push_back(40);
    // arr1.push_back(50);
    // arr1.push_back(30);
    // arr1.push_back(40);
    // arr1.push_back(50);
    // arr1.push_back(50);

    arr1.reserve(100); // Set the capacity directly to 100

    cout << arr1.max_size() << endl; // Maximum size that can vector take

    cout << "Size = " << arr1.size() << endl;
    arr1.pop_back();

    cout << "Size = " << arr1.size() << endl;
    cout << "Capacity = " << arr1.capacity() << endl; // Return number of block assign to vector
    // if no size is given then capacity start from 2^n n->[0, n]
    // else taking the starting size and curr_size * 2

    cout << arr1.front() << endl;
    cout << arr1.back() << endl;
    cout << arr1.empty() << endl;
    
    // vector<int> arr2(10); // This refers to creating a container with 10 size of blocks initialized by 0 by default


    // vector<int> arr3(10, 2); // Same as above just all blocks are intialized by 2
    
    // cout << *(arr3.begin()) << endl; // It return the iterator pointing to the first block of vector



    return 0;
}