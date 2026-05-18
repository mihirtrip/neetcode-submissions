class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_set<char> st;

        int left = 0;
        int max_len = 0;

        for(int i = 0; i < s.size(); i++) {

            while(st.find(s[i]) != st.end()) {
                st.erase(s[left]);
                left++;
            }

            st.insert(s[i]);

            max_len = max(max_len, i - left + 1);
        }

        return max_len;
    }
};