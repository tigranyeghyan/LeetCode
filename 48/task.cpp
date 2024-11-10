#include <vector>
class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) 
    {
        size_t n = matrix.size(); 
        for(size_t i = 0; i < n/2; ++i)
        {
            std::swap(matrix[i], matrix[n - i - 1]);
        }
        for(size_t i = 0; i < n; ++i)
        {
            for(size_t j = i + 1; j < n; ++j)
            {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};