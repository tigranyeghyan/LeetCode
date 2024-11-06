#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) 
    {
        int size = nums.size();
        int res = nums[0];
        for(size_t i = 1; i < size; ++i)
        {
            res ^= nums[i];  
        }
        return res;
        
    }
};