class Solution {
public: 
    vector<vector<int>>ans;
    void back(int index, vector<int>nums, vector<int>curr){
        ans.push_back(curr);

        for(int i =index; i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1]){
                continue;
            }
            
            curr.push_back(nums[i]);
            back(i+1, nums, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<int>curr;
       sort(nums.begin(),nums.end());
       back(0,nums,curr);
       return ans;
    }
};
