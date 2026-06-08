class Solution {
public:
    vector<vector<int>>ans;
    vector<int>curr;
    void back(int index, vector<int>& nums, int target){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(target<0){
            return;
        }
        for(int i =index;i<nums.size();i++){
            curr.push_back(nums[i]);

            back(i,nums, target-nums[i]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        back(0, nums, target);
        return ans;
    }
};
