class Solution {
public:
    vector<int>dp;
    int ans = -1;
    int dfs(int amount, vector<int>&coin ){
        if (amount == 0) return 0;
        if(amount < 0) return 100000;
        if(dp[amount] != -1){
            return dp[amount];
        }
        int ans = 100000;
        for(int i = 0;i<coin.size();i++){
            ans = min(ans,1+dfs(amount-coin[i],coin));
        }
        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount+1,-1);
        int ans = dfs(amount,coins);
        if(ans>=100000){
            return -1;
        }
        return ans;
    }
};
