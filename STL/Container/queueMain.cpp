#include<IOSTREAM>
#include<queue>

using namespace std;

int main()
{
    queue<int> queue1;

    queue1.push(10);
    queue1.push(20);
    queue1.push(30);
    queue1.push(40);
    queue1.push(50);
    queue1.push(60);

    cout << queue1.front() << endl;
    queue1.pop();
    cout << queue1.front() << endl;

    cout << queue1.back() << endl;



    return 0;
}