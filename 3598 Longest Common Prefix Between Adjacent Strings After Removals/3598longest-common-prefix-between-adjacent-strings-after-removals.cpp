#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(const string &a, const string &b)
    {
        int len = 0;
        while (len < a.size() && len < b.size() && a[len] == b[len])
            len++;
        return len;
    }

public:
    vector<int> longestCommonPrefix(vector<string> &words)
    {
        int n = words.size();
        if (n ==1)
            return {0};
        else if(n==2)return {0,0};
        vector<int> adj(n - 1);
        for (int i = 0; i < n - 1; i++)
        {
            adj[i] = solve(words[i], words[i + 1]);
        }

        vector<int> pre(n - 1), suff(n - 1);
        pre[0] = adj[0];
        for (int i = 1; i < n - 1; i++)
        {
            pre[i] = max(pre[i - 1], adj[i]);
        }
        suff[n - 2] = adj[n - 2];
        for (int i = n - 3; i >= 0; i--)
        {
            suff[i] = max(suff[i + 1], adj[i]);
        }

        vector<int> ans(n,0);
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {

                ans[i] = suff[1];
            }
            else if (i == n - 1)
            {

                ans[i] = pre[n - 3];
            }
            else
            {
                int l = (i >= 2) ? pre[i - 2] : 0;
                int r = (i + 1 <= n - 2) ? suff[i + 1] : 0;
                int temp = solve(words[i - 1], words[i + 1]);
                ans[i] = max({l, r, temp});
            }
        }
        return ans;
    }
};