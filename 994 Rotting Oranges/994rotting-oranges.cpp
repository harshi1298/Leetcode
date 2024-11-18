class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));
        queue < pair<int, int>> que;
        int fresh = 0,r=0;
        for (int i = 0; i < row ; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2){
                    que.push({i, j});
                    r++;}
                if (grid[i][j] == 1)
                    fresh++;
            }
        }
        int ans = 0;
        while (!que.empty()) {
            int k = que.size();
            fresh = fresh - k;
            while (k--) {
                int x = que.front().first, y = que.front().second;
                que.pop();
                 int dx[4] = {0, 0, 1, -1};
                 int dy[4] = {1, -1, 0, 0};
                for (int i = 0; i < 4; ++i) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx < 0 || ny < 0 || nx >= row || ny >= col ||
                        grid[nx][ny] != 1)
                        continue;
                    grid[nx][ny] = 2;
                    que.push({nx, ny});
                }
            }
            if (!que.empty())
                ans++;
        }
        return fresh+r==0?ans:-1;
    }
};