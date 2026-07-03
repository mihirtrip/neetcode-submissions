class Solution {
   public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int first = 0;
        int second = 0;
        int third = 0;
        for (auto& a : triplets) {
            if (a[0] > target[0] || a[1] > target[1] || a[2] > target[2]){
                continue;
            } 
            first = max(first, a[0]);
            second = max(second, a[1]);
            third = max(third, a[2]);
        }
        if (target[0] == first && target[1] == second && target[2] == third) {
            return true;
        }
        return false;
    }
};
