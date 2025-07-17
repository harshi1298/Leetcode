#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    vector<vector<bool>> ispal;
    vector<vector<string>> ans;
    void solve(int i, int j, vector<string> temp, string s)
    {
        if (i > j)
        {
            ans.push_back(temp);
            return;
        }
        for (int ind = i; ind <= j; ind++)
        {
            if (ispal[i][ind])
            {
                temp.push_back(s.substr(i, ind - i + 1));
                solve(ind + 1, j, temp, s);
                temp.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        int n = s.length();
        ispal.resize(n, vector<bool>(n, 0));
        for (int i = 0; i < n; i++)
        {
            ispal[i][i] = 1;
        }
        for (int i = 0; i < n - 1; i++)
            ispal[i][i + 1] = (s[i] == s[i + 1]);
        for (int diff = 2; diff < n; diff++)
        {
            for (int i = 0; i < n - diff; i++)
            {
                int j = diff + i;
                ispal[i][j] = (s[i] == s[j] && ispal[i + 1][j - 1]);
            }
        }
        solve(0, n - 1, {}, s);
        return ans;
    }
};