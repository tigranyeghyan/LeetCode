#include <vector>

class Solution {
public:
    int trap(std::vector<int>& height) 
    {   
        int val = 0;
        size_t i = 0;
        size_t j = height.size() - 1;
        int lmax = height[i];
        int rmax = height[j]; 
        while(i < j)
        {
            if(height[i] >= height[j])
            {
                --j;
                if(height[j] > rmax)
                {
                    rmax = height[j];
                }
                val += rmax - height[j];
            }
            else
            {
                ++i;
                if(height[i] > lmax)
                {
                    lmax = height[i];
                }
                val += lmax - height[i];
            }
        }
        return val;
    }
};