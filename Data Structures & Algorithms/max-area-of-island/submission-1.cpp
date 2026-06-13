class Solution {
public:
    int ans = 0;
    int dfs(vector<vector<int>> grid, vector<vector<int>>& vis, int row, int col) {
        if (row < 0 || row == grid.size() || col < 0 || col == grid[0].size() || vis[row][col] == 2 || grid[row][col]== 0) {
            return 0;
        }
        vis[row][col] = 2;
        return 1+ dfs(grid, vis, row - 1, col)+
        dfs(grid, vis, row + 1, col) +
        dfs(grid, vis, row, col - 1) +
        dfs(grid, vis, row, col + 1);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        int num_island = 0;
        int area = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1 && vis[i][j] != 2) {
                    area = dfs(grid, vis, i, j);
                    num_island++;
                }
                ans = max(ans,area);
            }
        }
        return ans;
    }
};
