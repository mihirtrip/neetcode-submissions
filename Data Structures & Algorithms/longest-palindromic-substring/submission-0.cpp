class Solution {
public:
    string ans = "";
    vector<vector<int>> dp;

    bool dfs(int i, int j, string& s) {
        if(i >= j) return true;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] != s[j]) {
            return dp[i][j] = false;
        }

        return dp[i][j] = dfs(i + 1, j - 1, s);
    }

    string longestPalindrome(string s) {
        int n = s.size();
        dp.assign(n, vector<int>(n, -1));

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(dfs(i, j, s)) {
                    if(j - i + 1 > ans.size()) {
                        ans = s.substr(i, j - i + 1);
                    }
                }
            }
        }

        return ans;
    }
};