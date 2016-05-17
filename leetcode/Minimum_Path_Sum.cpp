class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int gridRowSize = grid.size();
        int gridColSize = grid[0].size();
        int i, j;
        for(i = gridRowSize - 1; i >= 0; i--) {
            for(j = gridColSize - 1; j >= 0; j--) {
                if(i == gridRowSize-1 && j == gridColSize - 1)
                    continue;
                else if(i == gridRowSize-1)
                    grid[i][j] = grid[i][j]+grid[i][j+1];
                else if(j == gridColSize-1)
                    grid[i][j] = grid[i][j] + grid[i+1][j];
                else
                    grid[i][j] = grid[i][j] + min(grid[i+1][j], grid[i][j+1]);
            }
        }
        return grid[0][0];
    }
};




class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            for(int j=1; j<grid[0].size(); ++j)
                grid[0][j] += grid[0][j-1];
            for(int i=1; i<grid.size(); ++i)
                grid[i][0] += grid[i-1][0];

            if(grid.size() == 1) {
                int idx = grid[0].size();
                if(idx == 1)
                    return grid[0][0];
                else
                    return grid[0][idx-1];
            }

            int i, j;
            for(i=1; i<grid.size(); ++i)
                for(j=1; j<grid[i].size(); ++j)
                    grid[i][j] = grid[i][j] + min(grid[i-1][j], grid[i][j-1]);
            return grid[i-1][j-1];
        }
};

