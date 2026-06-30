class Solution {
   public:
    int dfs(int index, vector<int>& nums, vector<int>& dp) {
        if (index >= nums.size() - 1) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        int mini = INT_MAX;

        for (int jump = 1; jump <= nums[index]; jump++) {
            int next = dfs(index + jump, nums, dp);

            if (next != INT_MAX) {
                mini = min(mini, 1 + next);
            }
        }

        return dp[index] = mini;
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return dfs(0, nums, dp);
    }
};