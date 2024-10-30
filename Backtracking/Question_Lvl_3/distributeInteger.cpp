#include<IOSTREAM>
#include<VECTOR>
#include<unordered_map>

using namespace std;

bool isPossible(unordered_map<int, int> &mapping, vector<int> &arr, int index)
{
    if(index >= arr.size())  return true;

    for(auto i : mapping)
    {
        if((i.second - arr[index]) < 0) continue;

        mapping[i.first] -= arr[index];
        bool response = isPossible(mapping, arr, index + 1);
        if(response) return true;
        mapping[i.first] += arr[index];
    }

    return false;

}

int main()
{
    vector<int> arr = {8, 8, 8, 8, 3, 3};
    vector<int> quantity = {2, 1, 3};
    unordered_map<int, int> mapping;

    for(auto i : arr)
    {
        mapping[i]++;
    }

    if(isPossible(mapping, quantity, 0)) cout << "Yes it is possible" << endl;
    else cout << "No it is not possible" << endl;


    return 0;
}