#include <vector>

class Solution {
public:
    void sortColors(std::vector<int>& nums) 
    {
        int size = nums.size();
        int min = *std::min_element(nums.begin(), nums.end());
        int max = *std::max_element(nums.begin(), nums.end());
        int range = max - min + 1;
        std::vector<int> countArray(range, 0);
        for(int i = 0; i < size; ++i)
        {
            countArray[nums[i] - min]++;
        }
        for(int i = 1; i < range; ++i)
        {
            countArray[i] += countArray[i - 1];
        }
        std::vector<int> sortedArray(size);
        for(int i = 0; i < size; ++i)
        {
            sortedArray[countArray[nums[i] - min] - 1] = nums[i];
            countArray[nums[i] - min]--;
        }
        for(int i = 0; i < size; ++i)
        {
            nums[i] = sortedArray[i];
        } 
    }
};