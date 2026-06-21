class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1);
        if(n<2) return 1;

        int num_1 = 1;
        int num_2 = 1;
        int curr;
        for(int i = 2;i<=n;i++){
            curr = num_1 + num_2;
            num_1 = num_2;
            num_2 = curr;
        }
        return curr;
    }
};
