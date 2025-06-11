class Solution {
private:
    vector<vector<vector<long long>>> dp;
    int mod = 1e9 + 7;

    long long getpower(int k, int l) {
        long long ans = 1;
        while (k > 0) {
            if (k % 2) {
                ans = (ans * l) % mod;
            }
            l = (1LL * l * l) % mod;
            k /= 2;
        }
        return ans;
    }

    int solve(vector<int>& nums, int i, int sum, int len, int k) {
        int n = nums.size();
        if (sum == k) {
            if (len == 0) return 0;
            return getpower(n - len, 2);
        }
        if (i >= n) return 0;
        if (dp[i][sum][len] != -1) return dp[i][sum][len];

        long long res = 0;
        if (sum + nums[i] <= k) {
            res += solve(nums, i + 1, sum + nums[i], len + 1, k);
        }
        res += solve(nums, i + 1, sum, len, k);

        return dp[i][sum][len] = res % mod;
    }

public:
    int sumOfPower(vector<int>& nums, int k) {
        int n = nums.size();
        dp = vector<vector<vector<long long>>>(n + 1, vector<vector<long long>>(k + 1, vector<long long>(n + 1, -1)));
        return solve(nums, 0, 0, 0, k);
    }
};
