#include<IOSTREAM>

using namespace std;

class First_Functor
{
    public:
        operator ()(int a, int b) 
        {
            // This will sort our array in descending 
            return a > b;
        }
};

int main()
{




    return 0;
}