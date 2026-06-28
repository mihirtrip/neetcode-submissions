class Solution {
   public:
    int dfs(int i, int j, string& word1, string& word2, vector<vector<int>>&dp) {
        if(j==word2.size()&&i==word1.size()){
            return 0;
        }
        if(i==word1.size()&&j!=word2.size()){
            return word2.size() - j;
        }
        if(i!=word1.size()&&j==word2.size()){
            return word1.size() - i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int opt1, opt2, opt3;
        if (word1[i] == word2[j]) {
            return dfs(i + 1, j + 1, word1, word2,dp);
        } else {
            opt1 = 1 + dfs(i,j+1,word1,word2,dp);
            opt2 = 1 + dfs(i+1,j,word1,word2,dp);
            opt3 = 1 + dfs(i+1,j+1,word1,word2,dp);
        }
        return dp[i][j] = min(opt1, min(opt2, opt3));
    }
    int minDistance(string word1, string word2) { 
        vector<vector<int>>dp(word1.size(),vector<int>(word2.size(),-1));
        return dfs(0, 0, word1, word2,dp);
        
        }
};
