class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        map<int,int>mp;
        for(int a : nums){
            mp[a]++;
        }
        for(auto &it: mp){
            pq.push(make_pair(it.second,it.first));
        }
        while(k>0&&!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};
