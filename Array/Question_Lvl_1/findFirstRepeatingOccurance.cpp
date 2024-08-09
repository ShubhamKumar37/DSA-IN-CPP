#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>

using namespace std;

void findFirstOccurance1(vector<int> &arr, int length)
{

    int ans = -1;

    for(int i = 0; i < length; i++)
    {
        for(int j = i + 1; j < length; j++)
        {
            if(arr[i] == arr[j])
            {
                ans = i;
                break;
            }
        }
        if(ans != -1) break;
    }

    cout << "Fist occurance of duplicate element is " << arr[ans] << endl;
}

void findFirstOccurance2(vector<int> &arr, int length)
{
    unordered_map<int, int> map;
    int ans = -1;

    for(auto i : arr)
    {
        map[i]++;
    }

    for(int i = 0; i < length; i++)
    {
        if(map[arr[i]] > 1)
        {
            ans = i;
            break;
        }
    }

    cout << "First occurance of duplicate element is " << arr[ans] << endl;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 3, 5, 4};
    int length = v.size();

    findFirstOccurance1(v, length);
    findFirstOccurance2(v, length);

    return 0;
}