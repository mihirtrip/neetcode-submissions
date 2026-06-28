class Solution {
   public:
    int dfs(int i, int j, string& s, string& t, vector<vector<int>>&dp) {
        if (j == t.size()) {
            return 1;
        }
        if (i >= s.size()) {
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int way1 = 0;
        int way2 = 0;
        int way3 = 0;
        if (s[i] == t[j]) {
            way1 = dfs(i + 1, j + 1, s, t,dp);
            way2 = dfs(i + 1, j, s, t,dp);
        } else {
            way3 = dfs(i + 1, j, s, t,dp);
        }
        return dp[i][j] =  way1 + way2 + way3;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        return dfs(0, 0, s, t, dp);
    }
};
