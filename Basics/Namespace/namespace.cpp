#include<IOSTREAM>

using namespace std;

void func1()
{
    cout << "Hi this is function 1" << endl;
}

namespace Shubham
{
    void func1()
    {
        cout << "Hi this is function 1 but in namespace" << endl;
    }
}

int main()
{
    func1();
    Shubham::func1();

    return 0;
}