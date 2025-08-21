class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j]) mat[i][j] += mat[i-1][j];
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j]) {
                    int minHeight = mat[i][j];
                    for (int k = j; k < m && mat[i][k]; k++) {
                        minHeight = min(minHeight, mat[i][k]);
                        ans += minHeight;
                    }
                }
            }
        }
        return ans;
    }
};
