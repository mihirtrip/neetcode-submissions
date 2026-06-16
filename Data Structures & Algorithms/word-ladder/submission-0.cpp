class Solution {
   public:
    vector<string> nextWord(string front, unordered_map<string, int>& mp) {
        vector<string> exi;

        for (int i = 0; i < front.size(); i++) {
            string temp = front;

            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (ch == front[i]) continue;

                temp[i] = ch;

                if (mp.find(temp) != mp.end()) {
                    exi.push_back(temp);
                }
            }
        }

        return exi;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wl) {
        unordered_map<string, int> mp;
        for (string a : wl) {
            mp[a]++;
        }
        mp.erase(beginWord);
        queue<string> q;
        q.push(beginWord);
        int level = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string front = q.front();
                q.pop();
                vector<string> temp;
                temp = nextWord(front, mp);
                for (string s : temp) {
                    mp.erase(s);
                    if (s == endWord) {
                        return level+1;
                    }
                    q.push(s);
                }
            }
            level++;
        }
        return 0;
    }
};
