class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> ans;
        queue<int> q;
        if (digits[n - 1] < 9) {
            digits[n - 1] = digits[n - 1] + 1;
            return digits;
        }
        int i = n;
        int carry = 0;
        while (i > 0) {
            int sum;
            if (i == n) {
                sum = digits[i - 1] + 1;
                int left = sum % 10;
                carry = sum / 10;
                ans.push_back(left);
            } else {
                sum = digits[i - 1] + carry;

                int left = sum % 10;
                carry = sum / 10;
                ans.push_back(left);
            }

            i--;
        }
        if (carry != 0) {
            ans.push_back(carry);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
