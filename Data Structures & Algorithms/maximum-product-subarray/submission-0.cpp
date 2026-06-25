class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pri = 1;
        int suf = 1;
        int  maxi = INT_MIN;
        for(int i =0;i<nums.size();i++){
           
            if(pri==0){
                pri=1;
            }
            if(suf==0){
                suf =1;
            }
            pri  = pri * nums[i];
            suf = suf * nums[n-i-1];
            maxi = max(maxi,max(pri,suf));
            
        }
        return maxi;
    }
};
