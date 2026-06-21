class Solution {
public:
    int help(int i, vector<int>& cost, vector<int>& dp) {
        if(i >= cost.size()) {
            return 0;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        int opt1 = help(i + 1, cost, dp);
        int opt2 = help(i + 2, cost, dp);

        return dp[i] = cost[i] + min(opt1, opt2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n, -1);

        return min(help(0, cost, dp),
                   help(1, cost, dp));
    }
};