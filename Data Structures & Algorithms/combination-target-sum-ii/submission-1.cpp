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
            if(i>index && nums[i]==nums[i-1]){
                continue;
            }



            curr.push_back(nums[i]);

            back(i+1,nums, target-nums[i]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        back(0,candidates, target);
        return ans;
    }
};
