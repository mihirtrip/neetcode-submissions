class Solution {
public:
    int help(int i, int end, vector<int>& nums, vector<int>& dp) {
        if(i > end) return 0;

        if(dp[i] != -1) return dp[i];

        int rob = nums[i] + help(i + 2, end, nums, dp);
        int skip = help(i + 1, end, nums, dp);

        return dp[i] = max(rob, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);

        return max(help(0,n-2,nums,dp1),help(1,n-1,nums,dp2));
    }
};
