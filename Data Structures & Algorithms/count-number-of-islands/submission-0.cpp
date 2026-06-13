class Solution {
   public:
    void dfs(vector<vector<char>> grid, vector<vector<int>>& vis, int row, int col) {
        if (row < 0 || row == grid.size() || col < 0 || col == grid[0].size() || vis[row][col] == 2 || grid[row][col]== '0') {
            return;
        }
        vis[row][col] = 2;
        // vector<vector<int>>pos(4,-1);
        // pos[0][0] =
        dfs(grid, vis, row - 1, col);
        dfs(grid, vis, row + 1, col);
        dfs(grid, vis, row, col - 1);
        dfs(grid, vis, row, col + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        int num_island = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1' && vis[i][j] != 2) {
                    dfs(grid, vis, i, j);
                    num_island++;
                }
            }
        }
        return num_island;
    }
};
