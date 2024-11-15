#include <string>
#include <stack>

class Solution {
public:
    int longestValidParentheses(std::string s) 
    {
        std::stack<int>st;
        st.push(-1);
        int cnt = 0;
        int size = s.size();

        for(int i = 0; i < size; ++i)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if(st.empty())
                {
                    st.push(i);
                }
                else
                {
                    int len = i - st.top();
                    cnt = cnt > len ? cnt : len;
                }
            }
        }
        return cnt;
    }
};