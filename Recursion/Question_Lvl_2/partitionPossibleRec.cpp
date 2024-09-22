#include<IOSTREAM>
#include<VECTOR>
#include<algorithm>
#include<MATH.H>

using namespace std;

bool isPossiblePartition(vector<int> &arr, int sum, int index)
{
    if(sum < 0 || index >= arr.size()) return false;

    if(sum == 0) return true;

    bool include = isPossiblePartition(arr, sum - arr[index], index + 1);
    bool exclude = isPossiblePartition(arr, sum, index + 1);

    return include || exclude;
}

bool findPartition(vector<int> &arr)
{
    int sum = 0;

    for(auto i : arr) sum += i;

    if(sum & 1) return false;

    return isPossiblePartition(arr, (sum >> 1), 0);

}

int main()
{
    vector <int> arr = {5, 4, 3, 2, 3, 1};

    if(findPartition(arr))
    {
        cout << "Partion is possible" << endl;
    }
    else{
        cout << "Partion is not possible" << endl;
    }


    return 0;
}