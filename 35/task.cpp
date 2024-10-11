#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) 
    {
        return binarySearch(nums, 0, nums.size() - 1,target);        
    }

    int binarySearch(const std::vector<int>& arr, int low, int high, int target)
    {
        if (low > high) 
        {
            return low;
        }

        int mid = low + (high - low) / 2;

        if (arr[mid] == target) 
        {
            return mid;
        }
        else if (arr[mid] < target) 
        {
            return binarySearch(arr, mid + 1, high, target);
        }
        else 
        {
            return binarySearch(arr, low, mid - 1, target);
        }
    }
};