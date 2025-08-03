class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(3, vector<long long>(n, LLONG_MIN));
        vector<vector<int>> len(3, vector<int>(n, 0));
        dp[0][0] = nums[0]; 
        len[0][0] = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                if(dp[0][i - 1] != LLONG_MIN){
                    dp[0][i] = dp[0][i - 1] + nums[i];
                    len[0][i] = len[0][i - 1] + 1;
                }
                if((nums[i]+nums[i-1]>dp[0][i])){
                    dp[0][i]=nums[i]+nums[i-1];
                    len[0][i]=2;
                }
            } 
            if (nums[i] < nums[i - 1]) {
                if(dp[0][i - 1] != LLONG_MIN){
                    dp[1][i] = dp[0][i - 1]  + nums[i];
                    len[1][i] = len[0][i - 1] + 1;
                }
                if(dp[1][i - 1] != LLONG_MIN){
                    long long cand = dp[1][i - 1] + nums[i];
                    if (cand > dp[1][i]) {
                        dp[1][i] = cand;
                        len[1][i] = len[1][i - 1] + 1;
                    }
                }
            }
            if (nums[i] > nums[i - 1]) {
                if(dp[1][i - 1] != LLONG_MIN){
                    dp[2][i] = dp[1][i - 1] + nums[i];
                    len[2][i] = len[1][i - 1] + 1;
                }
                if(dp[2][i - 1] != LLONG_MIN){
                    long long cand = dp[2][i - 1] + nums[i];
                    if (cand > dp[2][i]) {
                        dp[2][i] = cand;
                        len[2][i] = len[2][i - 1] + 1;
                    }
                }
            }
        }
        // for(int i = 0; i < 3; i++) {
        //     for(int j = 0; j < n; j++) cout << dp[i][j] << " ";
        //     cout << endl;
        // }
        long long result = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            if (len[2][i] >= 4)
                result = max(result, dp[2][i]);
        }

        return result == LLONG_MIN ? 0 : result;
    }
};
