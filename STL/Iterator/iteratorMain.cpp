#include <IOSTREAM>
#include <VECTOR>
#include <forward_list>

using namespace std;

int main()
{

    // forward_list<int> list;

    // list.push_front(10);
    // list.push_front(20);
    // list.push_front(30);
    // list.push_front(40);

    // forward_list<int>::iterator it = list.begin();

    // while(it != list.end())
    // {
    //     cout << *it++ << " ";
    // }

    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7};

    vector<int>::iterator it = v1.end();

    while (it != v1.begin())
    {
        // We have to decrease our pointer by one as it is already pointing to the end of end block so it will be 0 automatically
        it--;
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}