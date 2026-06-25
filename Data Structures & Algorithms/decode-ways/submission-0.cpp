class Solution {
public:
    int dfs(int idx,vector<int>&dp,string s){
        if(idx==s.length()) return 1;
        if(s[idx]=='0') return 0;

        if(dp[idx]!=0){
            return dp[idx];
        }
        int ways = dfs(idx+1,dp,s);
        if(idx+1<s.length()){
            int num = (s[idx]-'0')*10 + (s[idx+1]-'0');
            if(num>=10&&num<=26){
                ways += dfs(idx+2,dp,s);
            }
        }
        return dp[idx] = ways;

    }
    int numDecodings(string s) {
        vector<int>dp(s.length(),0);
        return dfs(0,dp,s);
    }
};
