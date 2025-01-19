class Solution {
public:
    int trapRainWater(vector<vector<int>>& h) {
        int ans = 0;
        int row = h.size(), col = h[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 1));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> que;
       for(int i=0;i<row;i++){
            que.push({h[i][0],{i,0}});
            vis[i][0]=0;
        }
        for(int i=0;i<col;i++){
            que.push({h[row-1][i],{row-1,i}});
            vis[row-1][i]=0;
        }
        for(int i=0;i<col;i++){
            que.push({h[0][i],{0,i}});
            vis[0][i]=0;
        }
        for(int i=0;i<row;i++){
            que.push({h[i][col-1],{i,col-1}});
            vis[i][col-1]=0;
        }
        int indx[4] = {-1, 1, 0, 0};
        int indy[4] = {0, 0, -1, 1};
        while (!que.empty()) {
            int x = que.top().second.first;
            int y = que.top().second.second;
            int hg=que.top().first;
            que.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + indx[i];
                int ny = y + indy[i];
                if (nx >= 0 && ny >= 0 && nx < row && ny < col && vis[nx][ny]) {
                    vis[nx][ny] = 0;
                    if (h[nx][ny] < hg) {
                        ans += (hg - h[nx][ny]);
                    }
                    que.push({max(h[nx][ny], hg), {nx, ny}});
                }
            }
        }
        return ans;
    }
};