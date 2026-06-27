class Solution {
   public:
    int sum = 0;

    int dfs(int index, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (index == nums.size() && target == 0) {
            return 1;
        }

        if (index >= nums.size()) {
            return 0;
        }

        if (target > sum || target < -sum) {
            return 0;
        }

        if (dp[index][target + sum] != -1) {
            return dp[index][target + sum];
        }

        int opt1 = dfs(index + 1, target - nums[index], nums, dp);
        int opt2 = dfs(index + 1, target + nums[index], nums, dp);

        return dp[index][target + sum] = opt1 + opt2;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        for (int num : nums) {
            sum += num;
        }
        if (target > sum || target < -sum) {
            return 0;
        }

        vector<vector<int>> dp(nums.size(), vector<int>(2 * sum + 1, -1));

        return dfs(0, target, nums, dp);
    }
};