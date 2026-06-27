class Solution {
   public:
    bool dfs(int i, int j, string& s1, string& s2, string& s3, vector<vector<int>>& dp) {
        if (i == s1.length() && j == s2.length()) {
            return true;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        bool opt1 = false;
        bool opt2 = false;

        if (i < s1.length() && s1[i] == s3[i + j]) {
            opt1 = dfs(i + 1, j, s1, s2, s3, dp);
        }

        if (j < s2.length() && s2[j] == s3[i + j]) {
            opt2 = dfs(i, j + 1, s1, s2, s3, dp);
        }

        return dp[i][j] = (opt1 || opt2);
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }

        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, -1));

        return dfs(0, 0, s1, s2, s3, dp);
    }
};