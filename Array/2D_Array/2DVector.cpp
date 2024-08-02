#include<iostream> 
#include<vector>

using namespace std;

int main()
{
    // vector<vector<int>> array; Only a 2D vector is created
    // vector<vector<int>> array(4); Only a 2D vector with 4 number of rows in it
    // vector<vector<int>> array(4, vector<int>(3)); A 2D vector with 4 rows and 3 column
    // vector<vector<int>> array(4, vector<int>(3, 10)); A 2D vector with 4 rows and 3 column where all the element are initialized with 10
    vector<vector<int>> array(4, vector<int>(3, 10));

    for(auto i : array)
    {
        for(auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }



    return 0;
}