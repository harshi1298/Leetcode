#include <bits/stdc++.h>
using namespace std;

#define pr pair<int, int>

class Solution
{
    int encrypt(vector<vector<int>> &m)
    {
        int ans = 0;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                ans |= (m[i][j] << (3 * (i * 3 + j))); 
            }
        }
        return ans;
    }

    vector<vector<int>> decrypt(int num)
    {
        vector<vector<int>> ans(2, vector<int>(3, 0));
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                ans[i][j] = (num >> (3 * (i * 3 + j))) & 7;
            }
        }
        return ans;
    }

public:
    int slidingPuzzle(vector<vector<int>> &board)
    {
        queue<pr> que;
        unordered_map<int, bool> vis;

        vector<vector<int>> temp = {{1, 2, 3}, {4, 5, 0}};
        int des = encrypt(temp);
        int start = encrypt(board);

        que.push({start, 0});
        vis[start] = true;

        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {-1, 1, 0, 0};

        while (!que.empty())
        {
            auto [u, steps] = que.front();
            que.pop();

            if (u == des)
                return steps;

            auto grid = decrypt(u);

            int x = -1, y = -1;
            for (int i = 0; i < 2; ++i)
            {
                for (int j = 0; j < 3; ++j)
                {
                    if (grid[i][j] == 0)
                    {
                        x = i;
                        y = j;
                    }
                }
            }

            for (int i = 0; i < 4; ++i)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 && nx < 2 && ny < 3)
                {
                    swap(grid[x][y], grid[nx][ny]);
                    int nextState = encrypt(grid);
                    if (!vis[nextState])
                    {
                        vis[nextState] = true;
                        que.push({nextState, steps + 1});
                    }
                    swap(grid[x][y], grid[nx][ny]); 
                }
            }
        }

        return -1; 
    }
};
