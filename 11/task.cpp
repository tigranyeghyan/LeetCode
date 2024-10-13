#include <vector>

class Solution 
{
public:
    int maxArea(std::vector<int>& height) 
    {
        int area = 0;
        int SIZE = height.size();
        auto start = height.begin();
        auto end = height.end() - 1;
        for (int i = 0; start <= end; ++i) 
        {
            int min = std::min(*start, *end);
            int temp = min * (SIZE - i - 1);
            if(*start <= *end)
            {
                ++start;
            }    
            else
            {
                --end;
            }
            if(temp > area)
            {
                area = temp;
            }
        }
        return area;
    }
};