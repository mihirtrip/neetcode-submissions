class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        map<int,int> mp;

        for (int a : nums) {
            mp[a]++;
        }

        for (auto &it : mp) {
            if (pq.size() < k) {
                pq.push({it.second, it.first});
            } 
            else {
                if (pq.top().first < it.second) {
                    pq.pop();
                    pq.push({it.second, it.first});
                }
            }
        }

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};