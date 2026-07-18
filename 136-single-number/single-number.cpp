class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mapp;
        for (int i = 0; i < n; i++) {
            mapp[nums[i]]++;
        }
        for (auto it : mapp) {
            if (it.second == 1) {
                return it.first;
            }
        }
        return -1;
    }
};