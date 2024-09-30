#include<IOSTREAM>
#include<VECTOR>

using namespace std;

vector<int> mergeArray(vector<int> &arr1, vector<int> &arr2)
{
    int i = 0;
    int j = 0;
    vector<int> ans;

    while(i < arr1.size() && j < arr2.size())
    {
        if(arr1[i] < arr2[j]) ans.push_back(arr1[i++]);
        else ans.push_back(arr2[j++]);
    }

    while(i < arr1.size()) ans.push_back(arr1[i++]);
    while(j < arr2.size()) ans.push_back(arr2[j++]);

    return ans;
}

int main()
{

    vector<int> arr1 = {4, 6, 7, 8, 9};
    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9};

    vector<int> ans = mergeArray(arr1, arr2);

    for(auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;



    return 0;
}