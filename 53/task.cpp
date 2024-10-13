#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) 
    {
        int size = nums.size();
        int max = nums[0];
        int result = max; 
        for(int i = 1; i < size; ++i)
        {
            max = std::max(nums[i], nums[i] + max);
            result = std::max(max, result); 
        }
        return result;
    }
};