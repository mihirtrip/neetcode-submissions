class Solution {
public:
    vector<vector<int>> ans;
    void back(int start, vector<int>& nums, vector<int>& curr){
        ans.push_back(curr);

        for(int i =start; i<nums.size();i++){
            curr.push_back(nums[i]);
            back(i+1, nums, curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>curr;
        back(0, nums, curr);
        return ans;
    }
};
