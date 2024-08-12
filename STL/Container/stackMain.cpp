#include<IOSTREAM>
#include<STACK>

using namespace std;

int main()
{
    stack<int> stack1;

    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);

    cout << stack1.size() << endl;
    cout << stack1.top() << endl;
    stack1.pop();
    cout << stack1.top() << endl;
    cout << stack1.empty() << endl;


    return 0;
}