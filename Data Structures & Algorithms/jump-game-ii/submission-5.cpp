class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int currmost = 0;
        int farthest = 0;
        for(int i =0;i<nums.size()-1;i++){
            farthest = max(farthest,i+nums[i]);
            if(i==currmost){
                ans++;
                currmost = farthest;
            }
        }
        return ans;
    }
};
