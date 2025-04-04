// 155. Min Stack

class MinStack
{
public:
    stack<pair<int, int>> s;
    MinStack()
    {
    }

    void push(int val)
    {
        int minEle = val;
        if (!s.empty())
            minEle = min(s.top().second, val);
        s.push(pair<int, int>{val, minEle});
    }

    void pop()
    {
        if (s.empty())
            return;
        s.pop();
    }

    int top()
    {
        return s.top().first;
    }

    int getMin()
    {
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */