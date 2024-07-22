#include <IOSTREAM>
#include <VECTOR>
#include <algorithm>
#include <MATH.H>

using namespace std;

bool checkPrime(int num)
{
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}

void findPrime(int num)
{
    int *Arr = new int[num];
    fill(Arr, Arr + num, 0);

    Arr[0] = 1;
    Arr[1] = 1;

    for (int i = 2; i < num; i++)
    {
        if (Arr[i] == 0 && checkPrime(i) == false)
        {
            for (int k = i; k < num; k += i)
            {
                Arr[k] = 1;
            }
        }
    }

    cout << "These are the all prime number between " << num << endl;
    for (int i = 0; i < num; i++)
    {
        if (Arr[i] == 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;
    delete Arr;
}

int main()
{
    int num = 0;
    cout << "Enter the number = ";
    cin >> num;

    findPrime(num);

    return 0;
}