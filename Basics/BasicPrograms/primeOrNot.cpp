#include<IOSTREAM>
#include<MATH.H>

using namespace std;

bool checkPrime(int num)
{
    for(int i = 2; i <= sqrt(num); i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int num = 0;
    cout << "Enter the number = ";
    cin >> num;

    cout << "The given number is " << (checkPrime(num) ? "prime" : "not prime") << endl;

    return 0;
}