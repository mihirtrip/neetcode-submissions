class Solution {
public:
    bool isAnagram(string s, string t) {
        map<int,int>mp;
        if(s.length()!=t.length()) return false;
        for(char a:s){
            mp[a]++;
        }
        for(char c : t){
            if(mp[c]>0){
                mp[c]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
