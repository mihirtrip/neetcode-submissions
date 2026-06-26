class Solution {
   public:
    bool dfs(int index, string s, vector<string>& dict, vector<int>&dp) {
        if (index == s.size()) {
            return true;
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        if (index > s.size()) {
            return false;
        }
        for (string word : dict) {
            if (index + word.size() > s.size()) continue;
            bool match = true;
            for (int i = 0; i < word.size(); i++) {
                if (s[index + i] != word[i]) {
                    match = false;
                    break;
                }
            }
            if(match){
                if(dfs(index+word.size(),s,dict,dp)){
                    return dp[index] = true;
                }
            }
        }
        return dp[index] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) { 
        vector<int> dp(s.size(), -1);
        return dfs(0, s, wordDict,dp);
    }
};
