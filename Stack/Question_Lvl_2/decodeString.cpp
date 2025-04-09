// 394. Decode String

class Solution {
    public:
    
        int strToNum(string &s)
        {
            int ans = 0;
            for(int i = s.size() - 1; i >= 0; i--)
            {
                int val = s[i] - '0';
                ans = ans * 10 + val;
            }
            return ans;
        }
    
        string decodeString(string str) {
            string ans;
            stack<char> s;
    
            for(auto i : str)
            {
                if(i != ']') s.push(i);
                else 
                {
                    string temp;
                    string number;
                    int mul = 1;
    
                    while(!s.empty() && s.top() >= 'a' && s.top() <= 'z')
                    {
                        temp.push_back(s.top()); 
                        s.pop();
                    }
                    reverse(temp.begin(), temp.end());
    
                    if(!s.empty() && s.top() == '[') s.pop();
    
                    while(!s.empty() && s.top() >= '0' && s.top() <= '9')
                    {
                        number.push_back(s.top());
                        s.pop();
                    }
    
                    mul = number.size() == 0 ? 1 : strToNum(number);
                    
                    string tempAns;
                    for(int j = 0; j < mul; j++) tempAns += temp;
                    for(auto j : tempAns) s.push(j);
                }
            }
    
            while(!s.empty())
            {
                ans += s.top();
                s.pop();
            }
    
            reverse(ans.begin(), ans.end());
    
            return ans;
        }
    };