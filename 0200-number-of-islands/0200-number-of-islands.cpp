class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col) {
        int m = grid.size();
        int n = grid[0].size();
        // Boundary check
        if(row < 0 || col < 0 || row >= m || col >= n)
            return;
        // Stop if water or already visited
        if(grid[row][col] == '0')
            return;
        // Mark current land as visited
        grid[row][col] = '0';
        // Explore all 4 directions
        dfs(grid, row - 1, col);
        dfs(grid, row + 1, col);
        dfs(grid, row, col - 1);
        dfs(grid, row, col + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};