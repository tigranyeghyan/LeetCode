#include <vector>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) 
    {
        int target =  nums[0];
        int cnt = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] == target)
            {
                cnt++;
            }
            else
            {
                if(cnt > 0)
                {
                    cnt--;
                }
                else
                {
                    target = nums[i];
                    cnt = 1;
                }
            }
        }
        return target;  
    }
};