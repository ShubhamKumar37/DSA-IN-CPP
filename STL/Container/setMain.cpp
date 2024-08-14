#include<IOSTREAM>
#include<SET>
#include<VECTOR>
#include<unordered_set>

using namespace std;

int main()
{

    // Set or unordered_set always store unique values 

    vector<int> arr = {1, 2, 4, 30, 5, 6, 4, 2, 5, 6, 2, 5};

    // set<int> S;
    unordered_set<int> S;

    for(auto i : arr)
    {
        S.insert(i);
    }

    if(S.find(30) != S.end())
    {
        S.erase(S.find(30));
    }
    unordered_set<int>::iterator it = S.begin();


    while(it != S.end())
    {
        cout << *it++ << " ";
    }
    cout << endl;

    // S.clear();
    // cout << S.size() << endl;

    return 0;
}