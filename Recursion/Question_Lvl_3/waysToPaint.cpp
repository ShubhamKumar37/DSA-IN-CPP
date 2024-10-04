#include<IOSTREAM>

using namespace std;

int countWays(int n, int k)
{
    if(n == 1) return k;
    if(n == 2) return k + (k * (k - 1));

    return (k - 1) * (countWays(n - 1, k) + countWays(n - 2, k));    
}

int main()
{
    int n = 5;
    int k = 3;

    cout << "Number of ways to paint is " << countWays(n, k) << endl;


    return 0;
}