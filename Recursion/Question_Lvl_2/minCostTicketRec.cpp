#include <IOSTREAM>
#include <VECTOR>

using namespace std;

int findMinCost1(vector<int> &days, vector<int> &costs, int validDate, int index)
{
    if(index >= days.size()) return 0;

    if(validDate > days[index])
    {
        return findMinCost1(days, costs, validDate, index + 1);
    }

    int tempAns = INT_MAX;

    for(int i = 0; i < 3; i++)
    {
        int daysValid = 0;

        if(i == 0) daysValid = 1;
        if(i == 1) daysValid = 7;
        if(i == 2) daysValid = 30;

        int recAns = findMinCost1(days, costs, days[index] + daysValid, index + 1);

        tempAns = min(tempAns, recAns + costs[i]);
    }

    return tempAns;
}

void findMinCost2(vector<int> &days, vector<int> &costs, int validDate, int index, int minCost, int &ans)
{
    if(index >= days.size())
    {
        ans = min(ans, minCost);
        return ;
    }

    if(validDate > days[index])
    {
        findMinCost2(days, costs, validDate, index + 1, minCost, ans);
        return ;
    }

    for(int i = 0; i < 3; i++)
    {
        int daysValid = 0;

        if(i == 0) daysValid = 1;
        if(i == 1) daysValid = 7;
        if(i == 2) daysValid = 30;

        findMinCost2(days, costs, days[index] + daysValid , index + 1, minCost + costs[i], ans);
    }
}

int main()
{
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {2, 7, 15};
    int ans = INT_MAX;

    // cout << "Minimum cost of tickets = " << findMinCost1(days, costs, 0, 0) << endl;
    findMinCost2(days, costs, 0, 0, 0, ans);
    cout << "Minimum cost of tickets = " << ans << endl;

    return 0;
}