class Solution {
private:
    vector<int> dp;

    bool solve(int mask, int maxChoosableInteger, int remaining) {

        // Already calculated
        if (dp[mask] != -1)
            return dp[mask];

        for (int i = 1; i <= maxChoosableInteger; i++) {

            // i is already selected
            if (mask & (1 << i))
                continue;

            // Current player can directly reach/exceed target
            if (i >= remaining)
                return dp[mask] = true;

            // Choose i
            int newMask = mask | (1 << i);

            // After choosing i, opponent's turn.
            // If opponent cannot win, current player wins.
            if (!solve(newMask,
                       maxChoosableInteger,
                       remaining - i)) {
                return dp[mask] = true;
            }
        }

        // No move can guarantee a win
        return dp[mask] = false;
    }

public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {

        if (desiredTotal <= 0)
            return true;

        int sum = maxChoosableInteger *
                  (maxChoosableInteger + 1) / 2;

        // Even after using every number,
        // target cannot be reached.
        if (sum < desiredTotal)
            return false;

        dp.assign(1 << (maxChoosableInteger + 1), -1);

        return solve(0,
                     maxChoosableInteger,
                     desiredTotal);
    }
};