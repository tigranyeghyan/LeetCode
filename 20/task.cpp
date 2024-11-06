class Solution {
public:
    bool open_close(const char& first, const char& last)
    {
        switch(first)
        {
            case '{':
                return last == '}';
            case '[':
                return last == ']';
            case '(':
                return last == ')';
            default:
                return false;
        }
    }

    bool isValid(std::string s) 
    {
        size_t size = s.size();
        std::stack<char> stk;

        for (size_t i = 0; i < size; ++i)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                stk.push(s[i]);
            }
            else
            {
                if(stk.empty())
                {
                    return false;
                }
                else
                {
                    if(open_close(stk.top(), s[i]))
                    {
                        stk.pop();
                    }
                    else
                    {
                        stk.push(s[i]);
                    }
                }
            }
        }    
        return stk.empty();
    }
};