int nums ;
cin >> nums;



for(int i = 0; i < nums; i++)
{
    int n, k;
    cin >> n >> k;
    vector<int> arr;
    for(int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        arr.push_back(ele);
    }

    // Actual code start //

    k = (k % n);

    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());

    for(auto i : arr) cout << i << " ";
    cout << endl;

    // Actual code end //

}