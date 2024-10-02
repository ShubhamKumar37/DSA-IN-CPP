#include<IOSTREAM>

using namespace std;

int findDearrangment(int n){
    if(n == 2 || n == 1)
    {
        return n - 1;
    }

    return (n - 1)*(findDearrangment(n - 1) + findDearrangment(n - 2));
}

int main()
{
    int n = 3;

    cout << "Possible dearrangment = " << findDearrangment(n) << endl;


    return 0;
}