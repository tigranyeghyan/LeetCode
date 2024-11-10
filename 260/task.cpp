#include <vector>

class Solution {
public:
    std::vector<int> singleNumber(std::vector<int>& nums) 
    {
        uint res = 0;
        size_t size = nums.size();
        for(size_t i = 0; i < size; ++i)
        {
            res ^= nums[i];  
        }
        uint mask = (res & (-res));
        int v1 = 0, v2 = 0;
        for(size_t i = 0; i < size; ++i)
        {
            if(nums[i] & mask)
            {
                v1 ^= nums[i];
            }
            else
            {
                v2 ^= nums[i];
            }
        }
        return {v1, v2};
    }
};