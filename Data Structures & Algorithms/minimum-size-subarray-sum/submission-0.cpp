class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mini = INT_MAX;
        int left = 0;
        int sum = 0;
        for(int right = 0;right<nums.size();right++){
            sum += nums[right];
            int curr = 0;
            while(sum>=target){
                sum -= nums[left];
                int window = (right-left)+1;
                if(window<mini){
                    mini = window;
                }
                left++;
            }
        }
        if(mini==INT_MAX){
            return 0;
        }
        return mini;
    }
};