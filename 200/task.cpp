#include <vector>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) 
    {
        int cnt = 0;
        for(int i = 0; i < grid.size(); ++i)
        {
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(grid[i][j] == '1')
                {
                    cnt++;
                    syncIsland(grid, i, j);
                }
            }
        }
        return cnt;
    }
    void syncIsland(std::vector<std::vector<char>>& grid, int i, int j)
    {
        if(grid[i][j] == '0')
        {
            return;
        }
        grid[i][j] = '0';
        if(i > 0)
        {
            syncIsland(grid, i - 1, j);
        }
        if(j > 0)
        {
            syncIsland(grid, i , j - 1);
        }
        if(i < grid.size() - 1)
        {
            syncIsland(grid, i + 1, j);
        }
        if(j < grid[0].size() - 1)
        {
            syncIsland(grid, i , j + 1);
        }
    }
};