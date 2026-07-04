class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>ans;
        unordered_map<char,int>mp;
        for(int i =0;i<s.length();i++){
            mp[s[i]] = i;
        }
        int start = 0;
        int end = 0;
        for(int i =0;i<s.length();i++){
            end = max(end,mp[s[i]]);
            if(end==i){
                ans.push_back(end-start+1);
                start = end+1;
            }
        }
        return ans;
    }
};
