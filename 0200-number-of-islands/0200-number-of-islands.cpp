static const auto fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:

    void bfs (vector<vector<char>> &grid, int row, int col){
        int m = grid.size();
        int n = grid[0].size();

        // boundry condition
        if(row < 0 || col < 0 || row >= m || col >= n) return;

        // if current node is already visited or is water
        if(grid[row][col] == '0') return;

        //checking neighbors 
        grid[row][col] = '0';
        bfs( grid, row - 1, col);
        bfs( grid, row + 1, col);
        bfs( grid, row, col - 1);
        bfs( grid, row, col + 1);

    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0 ; 
        for ( int i = 0 ; i < row ; i++ ){
            for(int j = 0 ; j < col ; j++ ){
                if(grid[i][j] == '1'){
                    count++;
                    bfs(grid, i, j);
                }
            }
        }
        return count;
    }
};