#include<iostream>

using namespace std;

double findPrecised(double num, int target)
{
    int prec = 0;
    double dec = 1;
    cout << "Enter the precision = ";
    cin >> prec;

    for(int i = 0; i < prec; i++)
    {
        dec = dec * 10;
        double iPrec = num;
        for(int j = 0; j < 10; j++)
        {
            double tempAns = iPrec + (j / dec);
            if(tempAns * tempAns <= target)
            {
                num = tempAns;
            }
        }
    }

    return num;

}

double findSquareRoot(int num)
{
    if(num == 0)
    {
        return 0;
    }

    int s = 1, e = num;
    long long int mid = s + ((e - s) >> 1);
    int ans = 0;

    while(s <= e)
    {
        long long int square = mid * mid;

        if(square == num)
        {
            ans = mid;
            break;
        }
        else if(square < num)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }

        mid = s + ((e - s) >> 1);
    }

    // double precisedAns = (double)ans;
    return findPrecised((double)ans, num);

}

int main()
{
    int num; 
    cout << "Enter the value of num = ";
    cin >> num;

    cout << "Square root of num (approx.) is " << findSquareRoot(num) << endl;
    printf("%.10d", findSquareRoot(num));

    
    return 0;
}