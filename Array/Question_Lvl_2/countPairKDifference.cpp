#include<IOSTREAM>
#include<VECTOR>
#include<algorithm>

using namespace std; 

int findKDiffPair(vector<int> &arr, int length, int k)
{
    sort(arr.begin(), arr.end());

    int i = 0, j = 1, ans = 0;

    while(j < length)
    {
        int diff = abs(arr[i] - arr[j]);

        if(i == j) j++;
        else if(diff == k)
        {
            ans++;
            cout << ans << endl;
            int T1 = arr[i++];
            int T2 = arr[j++];

            while(j < length && T1 == arr[i] && T2 == arr[j])
            {
                j++;
            }
        }

        else if(k < diff) j++;
        else i++;
    }

    return ans;
}

int main()
{
    vector<int> arr;
    int k;
    cin >> k;

    for(;;)
    {
        int ele;
        cin >> ele;
        if (ele == -1) break;

        arr.push_back(ele);
    }


    cout << "Number of pair with K differnce in abs = " << findKDiffPair(arr, arr.size(), k) << endl;
    
    return 0;
}