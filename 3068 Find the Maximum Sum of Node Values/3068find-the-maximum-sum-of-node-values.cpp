class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long ans = 0, temp = LLONG_MAX, count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            long long xor_val = nums[i] ^ k;
            if (xor_val > nums[i]) {
                count++;
                ans += xor_val;
            } else {
                ans += nums[i];
            }
            temp = min(temp, abs(nums[i]-xor_val));
        }

        if (count % 2) {
            return ans - temp;
        }
        return ans;
    }
};
