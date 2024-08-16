#include<IOSTREAM>
#include<VECTOR>
#include<algorithm>

using namespace std;

class Comparator
{
    public:
    bool operator()(int &a, int &b)
    {
        return a > b;   
    }
};

int main()
{

    vector<int> v1 = {4, 3, 5, 6, 7, 4};

    sort(v1.begin(), v1.end(), Comparator());

    for(auto i : v1)
    {
        cout << i << " ";
    }
    cout << endl;


    return 0;
}