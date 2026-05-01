class Solution {
public:
    bool isAnagram(string s, string t) {
        map<int,int>mp;
        if(s.length()!=t.length()) return false;
        for(char a:s){
            mp[a]++;
        }
        for(char a: t){
            if(mp[a]>0){
                mp[a]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
