class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        set<int> s;

        for(int a : nums) {
            s.insert(a);
        }

        int maxi = 0;

        for(int a:nums){
            if(s.find(a-1)==s.end()){
                int len = 1;
                int current = a;
                while(s.find(current+1)!=s.end()){
                    len++;
                    current++;
                }
                maxi = max(len,maxi);
            }
            
        }

        return maxi;
    }
};