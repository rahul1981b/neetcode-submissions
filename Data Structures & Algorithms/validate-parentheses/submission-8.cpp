class Solution {
public:
    bool isValid(string s) {
        if ((s.size() < 2) || (s[0] == ']') || (s[0] == '}') || (s[0] == ')'))
            return false;

        vector<char> res;
        char big = '[';
        char curley = '{';
        char small = '(';

        for (int i = 0; i < s.size(); i++)
        {
            if ((s[i] == '[') || (s[i] == '{') || (s[i] == '('))
            {
                res.push_back(s[i]);
            }
            else if ((s[i] == ']') || (s[i] == '}') || (s[i] == ')'))
            {
                char temp = res.size() > 0 ? res.back() : '\0';
                if (((s[i] == ']') && (temp == big)) ||
                    ((s[i] == '}') && (temp == curley)) ||
                    ((s[i] == ')') && (temp == small)))                
                {
                    res.pop_back();
                }
            }
            else
                return false;
        }
        return (res.size() == 0);
    }
};
