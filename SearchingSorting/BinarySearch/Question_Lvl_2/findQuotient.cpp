#include<IOSTREAM>


using namespace std;

// Find the quotient without using / and %, no precision is required so only the nearest integer will be returned

int findQuotient(int divident, int divisor)
{
    int s = 0;
    int e = divident;
    int ans = divident;
    int mid = s + ((e - s) >> 1);

    while(s < e)
    {
        int value = mid * divisor;
        if(value == divident)
        {
            return mid;
        }
        else if(value < divident)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid;
        }

        mid = s + ((e - s) >> 1);
    }

    return ans;
}

int main()
{
    int divident = 44;
    int divisor = 11;

    int ans = findQuotient(abs(divident), abs(divisor));
    if((divident < 0 && divisor >= 0) || (divident >= 0 && divisor < 0))
    {
        ans = -ans;
    }
    cout << "Quotient is " << ans << endl;

    return 0;
}