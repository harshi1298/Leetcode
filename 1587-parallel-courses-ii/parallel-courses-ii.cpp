class Solution {
private:
    int n, k;
    vector<int> prereq;
    vector<int> dp;

    int solve(int mask) {
        // All courses completed
        if (mask == (1 << n) - 1) {
            return 0;
        }

        if (dp[mask] != -1) {
            return dp[mask];
        }

        // Find all courses whose prerequisites are completed
        int available = 0;

        for (int i = 0; i < n; i++) {

            // Course already completed
            if (mask & (1 << i)) {
                continue;
            }

            // All prerequisites of i are completed
            if ((prereq[i] & mask) == prereq[i]) {
                available |= (1 << i);
            }
        }

        int ans = n;

        // Number of available courses <= k
        if (__builtin_popcount(available) <= k) {
            ans = 1 + solve(mask | available);
        }
        else {

            // Try every subset of available courses
            // having exactly k courses
            int subset = available;

            while (subset) {

                if (__builtin_popcount(subset) == k) {
                    ans = min(
                        ans,
                        1 + solve(mask | subset)
                    );
                }

                subset = (subset - 1) & available;
            }
        }

        return dp[mask] = ans;
    }

public:
    int minNumberOfSemesters(
        int n,
        vector<vector<int>>& relations,
        int k
    ) {

        this->n = n;
        this->k = k;

        prereq.assign(n, 0);
        dp.assign(1 << n, -1);

        for (auto& relation : relations) {

            int u = relation[0] - 1;
            int v = relation[1] - 1;

            prereq[v] |= (1 << u);
        }

        return solve(0);
    }
};