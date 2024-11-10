#include <string>
class Solution {
public:
    bool backspaceCompare(std::string s, std::string t) 
    {
        foo(s);
        foo(t);
        return s == t;
    }
    void foo(std::string& str)
    {
        int i = 0; 
        int j = 0;
        while(j != str.size())
        {
            if(str[j] != '#')
            {
                str[i] = str[j];
                ++i;
            }
            else if(i > 0)
            {
                --i;
            }
            ++j;
        }
        str.resize(i);
    }
};