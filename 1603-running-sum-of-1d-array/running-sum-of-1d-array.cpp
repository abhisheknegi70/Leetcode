class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> num;
        
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            num.push_back(sum);
        }
        return num;
        
    }
};