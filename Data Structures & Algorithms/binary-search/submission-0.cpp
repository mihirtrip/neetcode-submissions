class Solution {
public:
    int search(vector<int>& nums, int target) {

        int prev = 0;
        int end = nums.size() - 1;

        while(prev <= end) {

            int mid = prev + (end - prev)/2;

            if(nums[mid] == target) {
                return mid;
            }

            else if(nums[mid] < target) {
                prev = mid + 1;
            }

            else {
                end = mid - 1;
            }
        }

        return -1;
    }
};