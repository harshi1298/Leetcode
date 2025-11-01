#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    vector<vector<string>> dp;
    vector<vector<int>> overlap;
    vector<string> words;
    int n;
    string addstr(int i, int j) {
        return words[i] + words[j].substr(overlap[i][j]);
    }

    string solve(int mask, int i) {
        if (dp[mask][i] != "") return dp[mask][i];
        if (mask == (1 << n) - 1) return dp[mask][i] = words[i];

        string best = "";
        for (int j = 0; j < n; ++j) {
            if (mask & (1 << j)) continue; 
            int newMask = mask | (1 << j);
            string next = words[i] +
                          solve(newMask, j).substr(overlap[i][j]);
            if (best.empty() || next.size() < best.size())
                best = next;
        }
        return dp[mask][i] = best;
    }

public:
    string shortestSuperstring(vector<string>& wordsInput) {
        words = wordsInput;
        n = words.size();
        dp.assign(1 << n, vector<string>(n, ""));
        overlap.assign(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                int len = min(words[i].size(), words[j].size());
                for (int k = len; k > 0; --k) {
                    if (words[i].substr(words[i].size() - k) == words[j].substr(0, k)) {
                        overlap[i][j] = k;
                        break;
                    }
                }
            }
        }

        string ans = "";
        for (int i = 0; i < n; ++i) {
            string cur = solve(1 << i, i);
            if (ans.empty() || cur.size() < ans.size())
                ans = cur;
        }
        return ans;
    }
};
