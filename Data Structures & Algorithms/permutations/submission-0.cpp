class Solution {
public:
    vector<vector<int>>ans;
    vector<int>curr;
    vector<int>vis;

    void back(vector<int>nums){
        if(curr.size()==nums.size()){
            ans.push_back(curr);
            return;
        }
        for(int i =0;i<nums.size();i++){
            if(vis[i]==true){
                continue;
            }

            vis[i] = true;

            curr.push_back(nums[i]);
            back(nums);
            curr.pop_back();    
            vis[i] = false;

        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vis.resize(nums.size(), false);
        back(nums);
        return ans;
    }
};
