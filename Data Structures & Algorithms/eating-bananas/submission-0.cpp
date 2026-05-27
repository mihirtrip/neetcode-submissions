class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = -1;
        for (int a : piles) {
            if (a > max) {
                max = a;
            }
        }
        int min_time = -1;
        int low = 1;
        int high = max;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int time = 0;
            for (int a : piles) {
                time += (a / mid);

                if (a % mid != 0) {
                    time++;
                }
            }
            if (time > h) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
};
