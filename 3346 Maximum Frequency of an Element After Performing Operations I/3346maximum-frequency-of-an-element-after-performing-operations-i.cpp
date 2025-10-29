#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leftBound(vector<int>& a, int val) {
        int l = 0, r = a.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (a[m] < val)
                l = m + 1;
            else
                r = m;
        }
        return l;
    }

    int rightBound(vector<int>& a, int val) {
        int l = 0, r = a.size() - 1;
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (a[m] > val)
                r = m - 1;
            else
                l = m;
        }
        return l;
    }

    int maxFrequency(vector<int>& a, int k, int op) {
        sort(a.begin(), a.end());
        int n = a.size(), ans = 0;
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++) {
           freq[a[i]]++;
           ans=max(ans,freq[a[i]]);
        }
        for (int i = a[0]; i <= a[n - 1]; i++) {
            int l = leftBound(a, i - k);
            int r = rightBound(a, i + k);
            int cur = r - l + 1;
            if (freq.count(i))
                cur = min(cur, freq[i] + op);
            else
                cur = min(cur, op);
            ans = max(ans, cur);
        }
        return ans;
    }
};
