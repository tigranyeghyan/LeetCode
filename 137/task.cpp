#include <vector>
class Solution {
public:
    int singleNumber(std::vector<int>& nums) 
    {
        int size = nums.size();
        int res = 0;
        for(size_t i = 0; i < sizeof(int) * 8; ++i)
        {
            size_t cnt = 0;
            for(size_t j = 0; j < size; ++j)
            {
                cnt += (nums[j] & (1 << i)) == 0 ? 0 : 1;
            }
            if(cnt % 3)
            {
                res |= (1 << i);
            }
        }
        return res;
    }
};