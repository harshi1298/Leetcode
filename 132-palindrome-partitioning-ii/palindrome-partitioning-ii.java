class Solution {
    Integer dp[][];

    public int minCut(String s) {
        int n = s.length();
        dp = new Integer[n][n];
        return solve(0, n - 1, s);
    }

    public int solve(int i, int j, String s) {

        if (i >= j)
            return 0;

        if (dp[i][j] != null)
            return dp[i][j];

      
        if (ispal(s, i, j))
            return dp[i][j] = 0;

        int mincost = Integer.MAX_VALUE;

        for (int k = i; k < j; k++) {

            if (ispal(s, i, k)) {
                int count = 1 + solve(k + 1, j, s);
                mincost = Math.min(mincost, count);
            }
        }

        return dp[i][j] = mincost;
    }

    public boolean ispal(String s, int left, int right) {
        while (left < right) {
            if (s.charAt(left) != s.charAt(right))
                return false;
            left++;
            right--;
        }
        return true;
    }
}