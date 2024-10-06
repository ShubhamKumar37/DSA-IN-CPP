#include<IOSTREAM>
#include<STRING>

using namespace std;

int minOperation(string &str1, string &str2, int indexI, int indexJ)
{
    if(indexI >= str1.size() && indexJ >= str2.size()) return 0;
    if(indexI < str1.size() && indexJ >= str2.size()) return str1.size() - indexI;
    if(indexI >= str1.size() && indexJ < str2.size()) return str2.size() - indexJ;
    if(str1[indexI] == str2[indexJ]) return minOperation(str1, str2, indexI + 1, indexJ + 1);

    int includeOp = minOperation(str1, str2, indexI, indexJ + 1);
    int deleteOp = minOperation(str1, str2, indexI + 1, indexJ);
    int replaceOp = minOperation(str1, str2, indexI + 1, indexJ + 1);

    return min(includeOp, min(deleteOp, replaceOp)) + 1;
}

int main()
{
    string str1 = "Shubham";
    string str2 = "Kumar";

    cout << "Minimum number of operation required is " << minOperation(str1, str2, 0, 0) << endl;


    return 0;
}