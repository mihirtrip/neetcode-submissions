class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int a : nums){
            if(mp.find(a)!=mp.end()){
                return a;
            }
            else{
                mp[a]++;
            }
        }
    }
};
