class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fr, int st, int k) {
        int n = fr.size();
        int left = max(fr[0][0], st - k);
        left=min(left,st);
        int right = min(fr[n - 1][0], st + k);
        int len = right - left + 1;
        if(len<=0)return 0;
        vector<int> dp(len, 0); 
        int pos = lower_bound(fr.begin(), fr.end(), vector<int>{left, 0}) - fr.begin();
        while (pos < n && fr[pos][0] <= right) {
            if(fr[pos][0]>=left && fr[pos][0]<=right)
               dp[fr[pos][0] - left] = fr[pos][1];
                pos++;
        }

        for (int i = 1; i < len; ++i) {
            dp[i] += dp[i - 1];
        }
        int ans = 0;
        for (int i = 0; i <= k; ++i) {
            int l = max(left,st - i);
            int r = min(right,st + (k - 2 * i));
            if (l <= r) {
                int sum = dp[r - left];
                if (l > left) sum -= dp[l - left - 1];
                ans = max(ans, sum);
            }
            l = max(left,st - (k - 2 * i));
            r = min(st + i,right);
            if (l <= r) {
                int sum = dp[r - left];
                if (l > left) sum -= dp[l - left - 1];
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};
