#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int size = nums.size();
        std::vector<int> newvec{nums[0]};

        for(int i = 1; i < size; ++i)
        {
            if(nums[i] != newvec.back())
            {
                newvec.push_back(nums[i]);
            }
        }
        nums = newvec;
        return newvec.size(); 
    }
};


