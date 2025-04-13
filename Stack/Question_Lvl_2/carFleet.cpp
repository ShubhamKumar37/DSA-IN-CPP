// 853. Car Fleet

class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        vector<pair<int, int>> temp;
        stack<float> s;

        for (int i = 0; i < speed.size(); i++)
            temp.push_back({position[i], speed[i]});

        sort(temp.begin(), temp.end());

        for (int i = 0; i < temp.size(); i++)
        {
            float time = (float)(target - temp[i].first) / (float)(temp[i].second);
            while (!s.empty() && s.top() <= time)
                s.pop();
            s.push(time);
        }

        return s.size();
    }
};