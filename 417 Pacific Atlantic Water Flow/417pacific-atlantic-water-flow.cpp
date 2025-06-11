#include <bits/stdc++.h>
using namespace std;

#define pr pair<int, int>

class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &h)
    {
        int row = h.size();
        int col = h[0].size();
        vector<vector<int>> pacific(row, vector<int>(col, 0));
        vector<vector<int>> atlantic(row, vector<int>(col, 0));
        queue<pr> que;
        int indx[4] = {1, -1, 0, 0};
        int indy[4] = {0, 0, -1, 1};

        for (int i = 0; i < row; i++)
        {
            que.push({i, 0});
            pacific[i][0] = 1;
        }
        for (int i = 0; i < col; i++)
        {
            que.push({0, i});
            pacific[0][i] = 1;
        }
        bfs(h, que, pacific, indx, indy);

        for (int i = 0; i < row; i++)
        {
            que.push({i, col - 1});
            atlantic[i][col - 1] = 1;
        }
        for (int i = 0; i < col; i++)
        {
            que.push({row - 1, i});
            atlantic[row - 1][i] = 1;
        }
        bfs(h, que, atlantic, indx, indy);

        vector<vector<int>> ans;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }

private:
    void bfs(vector<vector<int>> &h, queue<pr> &que, vector<vector<int>> &vis, int indx[], int indy[])
    {
        int row = h.size(), col = h[0].size();
        while (!que.empty())
        {
            auto [x, y] = que.front();
            que.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + indx[i], ny = y + indy[i];
                if (nx >= 0 && ny >= 0 && nx < row && ny < col &&
                    !vis[nx][ny] && h[nx][ny] >= h[x][y])
                {
                    vis[nx][ny] = 1;
                    que.push({nx, ny});
                }
            }
        }
    }
};
