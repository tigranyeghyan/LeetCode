#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) 
    {
        int size = digits.size();
        int t = size;
        for(int i = size - 1; i >= 0; --i)
        {   
            if(digits[i] == 9)
            {
                digits[i] = 0;
                t--;
            }
            else 
            {
                break;
            }
        }
        if(t == 0)
        {
            digits[0] = 1;
            digits.push_back(0);
        }
        else
        {
            digits[--t] += 1;
        }
        return digits;
    }
};