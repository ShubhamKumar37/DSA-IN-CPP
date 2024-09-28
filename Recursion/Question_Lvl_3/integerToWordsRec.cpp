#include <IOSTREAM>
#include <VECTOR>
#include <STRING>

using namespace std;

string numToWord(int num, vector<pair<int, string>> &mp)
{

    if(num == 0) return "Zero";

    string a = "";
    string b = "";
    string c = "";

    for(auto i : mp)
    {
        if(i.first <= num)
        {
            b += i.second;
            if(num >= 100) // Because num is changing no i.first
            {
                a += (numToWord(num / i.first, mp) + " ");
            }

            if(num % i.first != 0) // This is the case where num is less then equal to 20
            {
                c += (" " + numToWord(num % i.first, mp));
            }

            break;
        }
    }

    return a + b + c;

}   

int main()
{
    int number = 23423123;
    vector<pair<int, string>> mp = {
        {1000000000, "Billion"},
        {1000000, "Million"},
        {1000, "Thousand"},
        {100, "Hundred"},
        {90, "Ninety"},
        {80, "Eighty"},
        {70, "Seventy"},
        {60, "Sixty"},
        {50, "Fifty"},
        {40, "Forty"},
        {30, "Thirty"},
        {20, "Twenty"},
        {19, "Nineteen"},
        {18, "Eighteen"},
        {17, "Seventeen"},
        {16, "Sixteen"},
        {15, "Fifteen"},
        {14, "Fourteen"},
        {13, "Thirteen"},
        {12, "Twelve"},
        {11, "Eleven"},
        {10, "Ten"},
        {9, "Nine"},
        {8, "Eight"},
        {7, "Seven"},
        {6, "Six"},
        {5, "Five"},
        {4, "Four"},
        {3, "Three"},
        {2, "Two"},
        {1, "One"},
    };

    cout << "Number to words is " << numToWord(number, mp) << endl;

    return 0;
}