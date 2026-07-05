class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        // Traverse from the last digit
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }

            // If digit is 9, make it 0 and carry over
            digits[i] = 0;
        }

        // If all digits were 9
        vector<int> ans(n + 1, 0);
        ans[0] = 1;
        return ans;
    }
};