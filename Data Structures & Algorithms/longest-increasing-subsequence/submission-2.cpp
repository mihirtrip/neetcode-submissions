class Solution {
public: 
    
    int dfs(int index,vector<int>&nums,vector<int>&dp){
        int ans = 1;
        if(dp[index]!=-1){
            return dp[index];
        }
        for(int i =index+1;i<nums.size();i++){
            if(nums[i]>nums[index]){
                ans = max(ans,1+dfs(i,nums,dp));
            }
        }
        return dp[index] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        int ans = 0;
        for(int i =0;i<nums.size();i++){
            ans = max(ans,dfs(i,nums,dp));
        }
        return ans;
    }
};
