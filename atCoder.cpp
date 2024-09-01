#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long n, t = 0;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (auto health : arr)
    {
        long long h = health;
        
        while(h > 0)
        {
            if(h >= 50000000)
            {
                h -= 50000000;
                t += 30000000;
                continue;
            }
            if(h >= 500000)
            {
                h -= 500000;
                t += 300000;
                continue;
            }
            if(h >= 5000)
            {
                h -= 5000;
                t += 3000;
                continue;
            }

            long long div = h / 5;
            long long rem = h % 5;
            h = h / 5;

            t += (div * 3);

            if(rem <= 2)
            {
                t += rem;
            }
            else
            {
                t += 3;
            }
            break;
        }
    }

    cout << t;

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// const ll INF = 1LL << 60;

// int main() {
//   ll N, T = 0;
//   cin >> N;

//   vector<ll> vec(N);

//   for (int i = 0; i < N; i++) {
//     cin >> vec[i];
//   }

//   for (int i = 0; i < N; i++) {
//     ll H = vec[i];

//     while (H > 0) {
//       if (H >= 50000000) {
//         H -= 50000000;
//         T += 30000000;
//         continue;
//       }

//       if (H >= 500000) {
//         H -= 500000;
//         T += 300000;
//         continue;
//       }

//       if (H >= 5000) {
//         H -= 5000;
//         T += 3000;
//         continue;
//       }

//       T++;

//       if (T % 3 == 0) {
//         H -= 3;
//       } else {
//         H--;
//       }
//     }
//   }

//   cout << T << endl;
//   return 0;
// }