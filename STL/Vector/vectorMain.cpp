#include<IOSTREAM>
#include<VECTOR>

using namespace std;
 
int main()
{
    vector<int> arr1; // This refers to creating a container with 0 size
    
    vector<int> arr2(10); // This refers to creating a container with 10 size of blocks initialized by 0 by default

    vector<int> arr3(10, 2); // Same as above just all blocks are intialized by 2


    return 0;
}