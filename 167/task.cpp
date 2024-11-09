#include <vector>

class Solution 
{
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) 
    {
        int j = numbers.size() - 1;
        int i = 0;
        while(numbers[i] + numbers[j] != target)
        {
            if(numbers[i] + numbers[j] > target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return {i+1, j+1};
    }
};