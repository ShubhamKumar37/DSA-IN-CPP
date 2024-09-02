#include<IOSTREAM>
#include<VECTOR>
#include<algorithm>

using namespace std; 

bool isPossiblePair(vector<int> &arr, int startValue, int s, int e, int k)
{
    int mid = s + ((e - s) >> 1);

    while(s <= e)
    {
        int diff = abs(arr[mid] - startValue);
        if(diff == k) return true;
        else if(diff < k) s = mid + 1;
        else e = mid - 1;

        mid = s + ((e - s) >> 1);
    }

    return false;
}

int findKDiffPair2(vector<int> &arr, int length, int k)
{
    int ans = 0;
    sort(arr.begin(), arr.end());

    for(int i = 0; i < length;)
    {
        bool possiblePair = isPossiblePair(arr, arr[i], i + 1, length - 1, k);

        if(possiblePair) ans++;

        while(i + 1 < length && arr[i] == arr[i + 1]) i++;

        i++;
    }

    return ans;
}

int findKDiffPair1(vector<int> &arr, int length, int k)
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


    // cout << "Number of pair with K differnce in abs = " << findKDiffPair1(arr, arr.size(), k) << endl;
    cout << "Number of pair with K differnce in abs = " << findKDiffPair2(arr, arr.size(), k) << endl;
    
    return 0;
}