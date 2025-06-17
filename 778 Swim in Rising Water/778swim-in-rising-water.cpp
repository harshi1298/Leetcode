#include <bits/stdc++.h>
using namespace std;
#define tp tuple<int, int, int>
class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int time=INT_MAX;
        priority_queue<tp, vector<tp>, greater<tp>> pq;
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        int indx[4] = {0, 0, -1, 1};
        int indy[4] = {-1, 1, 0, 0};
        pq.emplace(grid[0][0], 0, 0);
        vis[0][0]=1;
        while (!pq.empty())
        {
            auto [val, x, y] = pq.top();
            pq.pop();
            if(x==n-1 && y==m-1){
                time=min(time,val);
            }
            for (int i = 0; i < 4; i++)
            {
                int nx = x + indx[i];
                int ny = indy[i] + y;
                if (nx >= 0 && ny >= 0 && nx < n && ny < m)
                {
                    if (vis[nx][ny] == 0)
                    {
                        grid[nx][ny] = max(val, grid[nx][ny]);
                        vis[nx][ny] = 1;
                        pq.emplace(grid[nx][ny], nx, ny);
                    }
                }
            }
        }
        return time;
    }
};