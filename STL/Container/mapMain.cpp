#include<IOSTREAM>
#include<unordered_map>
// #include<pair>

using namespace std;

int main()
{
    unordered_map<int, int> map;
    unordered_map<int, int>::iterator it = map.begin();
    
    pair<int, int> p;

    p.first = 22;
    p.second = 33;

    map[2]++;
    map[1] = 3442;

    map.insert(p);


    while(it != map.end())
    {
        cout << (*it++).second << endl;
    }

    map.at(2) = 2342342;

    cout << map[2] << endl;

    map.erase(map.begin(), map.end());

    cout << map.size() << endl;
    map.clear();
    cout << map.size() << endl;

    return 0;
}