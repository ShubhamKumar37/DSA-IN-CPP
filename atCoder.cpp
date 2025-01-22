#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to check if a number is a power of two
bool isPowerOfTwo(int x) {
    return x > 0 && (x & (x - 1)) == 0;
}

// Function to calculate the fallback sum
int fallbackSum(int n) {
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += (i ^ (n - i + 1));
    }
    return sum;
}

// Recursive function to find the optimal permutation
bool solve(int index, int n, vector<int>& p, vector<bool>& used) {
    if (index > n) {
        return true; // Base case: permutation complete
    }

    for (int x = 1; x <= n; ++x) {
        if (!used[x] && isPowerOfTwo(x ^ index)) {
            p[index] = x;
            used[x] = true;
            if (solve(index + 1, n, p, used)) {
                return true;
            }

            // Backtracking step
            used[x] = false;
            p[index] = 0;
        }
    }
    return false; // No valid assignment found
}

int optimalPermutationSum(int n) {
    vector<int> p(n + 1, 0); // Permutation array (1-indexed)
    vector<bool> used(n + 1, false); // Tracks used numbers

    // Start solving from the first index
    if (!solve(1, n, p, used)) {
        return fallbackSum(n);
    }

    // Calculate the result for the valid permutation
    int result = 0;
    for (int i = 1; i <= n; ++i) {
        result += (p[i] ^ i);
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    cout << optimalPermutationSum(n) << endl;
    return 0;
}
