class Solution {
public:
    int way = 0;
    int dfs(int index, int amt,vector<int>&coins, vector<vector<int>>& dp){
         if(amt==0){
            return 1;
        }
        if(index>=coins.size()||amt<0){
            return 0;
        }
        if(dp[index][amt] != -1){
            return dp[index][amt];
        }
        int opt1 = dfs(index,amt-coins[index],coins,dp);
        int opt2 = dfs(index+1,amt,coins,dp);
        return dp[index][amt] = opt1+opt2;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return dfs(0,amount,coins,dp);
    }
};
