class Solution {
public:
    int dfs(int row, int col, vector<vector<int>>&grid, vector<vector<int>> & dp){
        if(row>=grid.size()||col>=grid[0].size()){
            return 0;
        }
        if(grid[row][col]==2){
            return 1;
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int way1 = dfs(row,col+1,grid,dp);
        int way2 = dfs(row+1,col,grid,dp);
        return dp[row][col] = way1+way2;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>grid(m,vector<int>(n,0));
        grid[m-1][n-1] = 2;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return dfs( 0, 0 , grid, dp );
    }
};
