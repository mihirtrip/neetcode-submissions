class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(int a: nums){
            pq.push(a);
        }
        k = k-1;
        while(k){
            pq.pop();
            k--;
        }
        return pq.top();
    }
};
