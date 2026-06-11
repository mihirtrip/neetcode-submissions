class Solution {
   public:
    vector<string> curr;
    vector<vector<string>>ans;
    bool is_palin( int left, int right, string& s) {

        while(left < right) {

            if(s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }
    void back(int start, string s) {
        if(start==s.length()){
            ans.push_back(curr);
            return;
        }
        for(int end = start; end<s.length();end++){
            if(is_palin(start, end , s)){
                curr.push_back(s.substr(start, end-start+1));
                back(end+1, s);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        string temp = "";
        back(0, s);
        return ans;
    }
};
