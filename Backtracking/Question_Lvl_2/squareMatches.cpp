#include<IOSTREAM>
#include<VECTOR>

using namespace std;

bool isPossible(vector<int> &arr, vector<int> &side, int index)
{
    if(index >= arr.size())
    {
        return side[0] == 0 && side[1] == 0 && side[2] == 0 && side[3] == 0;
    }

    bool ans = false;

    for(int i = 0; i < 4; i++)
    {
        if(side[i] - arr[index] < 0) continue;

        side[i] -= arr[index];
        ans = ans || isPossible(arr, side, index + 1);
        side[i] += arr[index];

        if(ans == true) return true;
    }

    return ans;
}

int main()
{

    vector<int> arr = {4, 4, 4, 2, 2};

    int sum = 0;
    for(auto i : arr) sum += i;

    if(sum % 4 == 0)
    {
        vector<int> side(4, (sum >> 2));

        if(isPossible(arr, side, 0))
        {
            cout << "Making square is possible" << endl;
        }
        else
        {
            cout << "Not possible" << endl;
        }
    }
    else
    {
        cout << "Square is not possible at all" << endl;
    }



    return 0;
}