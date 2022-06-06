class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currentSum = 0;
        for(int i =0;i<nums.size();i++){
            currentSum = max(nums[i], nums[i] + currentSum);
            maxSum = max(maxSum, currentSum);
        }
        return maxSum;
    }
};