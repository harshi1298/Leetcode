class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxs = 0;
        int sum= nums[0];
        for (int i= 1; i< nums.size(); i++) {
            if (nums[i] <= nums[i- 1]) {
                maxs = max(maxs, sum);
                sum = 0;
            }
            sum += nums[i];
        }
        return max(maxs, sum);
    }
};