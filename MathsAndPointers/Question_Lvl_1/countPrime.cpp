#include<IOSTREAM>
#include<VECTOR>

using namespace std;


int findPrimeCount(int num)
{

    if(num == 0 || num == 1) return 0;

    int count = 0;
    vector<bool> isPrime(num, true);

    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i < num; i++)
    {
        if(isPrime[i])
        {
            count++;

            int j = i + i;

            while(j < num)
            {
                isPrime[j] = false;
                j += i;
            }
        }
    }

    return count;
}

int main()
{
    int num;
    cout << "Enter the number = ";
    cin >> num;

    cout << "Number of prime in between the number is " << findPrimeCount(num) << endl;


    return 0;
}