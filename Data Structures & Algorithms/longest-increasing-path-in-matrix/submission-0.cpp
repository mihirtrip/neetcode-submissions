class Solution {
   public:
    int dfs(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (row >= matrix.size() || col >= matrix[0].size() || row < 0 || col < 0) {
            return 0;
        }
        if (dp[row][col] != -1) {
            return dp[row][col];
        }
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int ans = 0;
        int maxi = 1;
        for (auto& dir : dirs) {
            int nr = row + dir[0];
            int nc = col + dir[1];
            if (nr < matrix.size() && nc < matrix[0].size() && nr >= 0 && nc >= 0) {
                if (matrix[row][col] < matrix[nr][nc]) {
                    maxi = max(maxi, 1 + dfs(nr, nc, matrix, dp));
                }
            }
        }
        return dp[row][col] = maxi;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        int maxi = 1;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                int ans = dfs(i, j, matrix, dp);
                maxi = max(maxi, ans);
            }
        }

        return maxi;
    }
};
