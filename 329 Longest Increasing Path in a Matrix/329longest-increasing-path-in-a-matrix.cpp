class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    int dfs(vector<vector<int>>& matrix, int i, int j) {
        if (dp[i][j] != -1) return dp[i][j];
        int ans = 1;
        for (auto& d : dirs) {
            int x = i + d[0], y = j + d[1];
            if (x >= 0 && y >= 0 && x < n && y < m && matrix[x][y] > matrix[i][j]) {
                ans = max(ans, 1 + dfs(matrix, x, y));
            }
        }
        return dp[i][j] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        dp.assign(n, vector<int>(m, -1));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max(ans, dfs(matrix, i, j));
            }
        }
        return ans;
    }
};
