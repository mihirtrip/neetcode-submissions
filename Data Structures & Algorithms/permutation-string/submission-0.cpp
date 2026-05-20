class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>freq(26,0);
        vector<int>freq2(26,0);
        for(int i =0;i<s1.size();i++){
            freq[s1[i]-'a']++;
        }
        int sizee = s1.size();
        int left = 0;
        for(int i =0;i<s2.size();i++){
            freq2[s2[i]-'a']++;
            while(i-left+1>sizee){
                freq2[s2[left]-'a']--;
                left++;
            }
            if(freq==freq2){
                return true;
            }
        }
        return false;
    }
};
