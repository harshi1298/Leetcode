class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> temp(n + 1, 0);
        for (int i = 0; i < n; i++) {
            temp[i + 1] = temp[i] + nums[i];
        }
        long long ans = LLONG_MIN;
        for (int i = 0; i <= k; i++) {
            long long rs=0;
            for (int j = i + k; j <= n; j += k) {
                 rs += (temp[j]-temp[j-k]);
                ans = max(ans,rs);
                if (rs<0) rs=0;
            }
        }
        return ans;
    }
};
