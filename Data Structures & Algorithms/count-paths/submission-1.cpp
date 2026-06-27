class Solution {
public:
    int dfs(int row, int col, int m, int n, vector<vector<int>> & dp){
        if(row >= m || col >= n){
            return 0;
        }
        if(row == m-1 && col == n-1){
            return 1;
        }
        if(dp[row][col]!=-1){
            return dp[row][col];
        }
        int way1 = dfs(row,col+1,m,n,dp);
        int way2 = dfs(row+1,col,m,n,dp);
        return dp[row][col] = way1+way2;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return dfs( 0, 0 , m,n, dp );
    }
};
