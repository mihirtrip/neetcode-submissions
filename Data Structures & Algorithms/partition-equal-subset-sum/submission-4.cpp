class Solution {
   public:
    bool dfs(int index, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0) {
            return true;
        }
        if (index >= nums.size() || target<0) {
            return false;
        }
        if (dp[index][target] != -1) {
            return dp[index][target];
        }

        bool take = dfs(index + 1, target - nums[index], nums, dp);
        bool skip = dfs(index + 1, target, nums, dp);

        if (take || skip) {
            return dp[index][target] = true;
        }
        return dp[index][target] = false;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) {
            return false;
        }
        int target = sum / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        
        return dfs(0, target, nums, dp);
    }
};
