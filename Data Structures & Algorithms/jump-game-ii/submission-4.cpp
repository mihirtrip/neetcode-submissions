class Solution {
public:
    const int INF = 1e9;
    int dfs(int index, vector<int>& nums, vector<int>& dp) {
        if (index >= nums.size() - 1) {
            return 0;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        int mini = INF;

        for (int jump = 1; jump <= nums[index]; jump++) {
            mini = min(mini, 1 + dfs(index + jump, nums, dp));
        }

        return dp[index] = mini;
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return dfs(0, nums, dp);
    }
};