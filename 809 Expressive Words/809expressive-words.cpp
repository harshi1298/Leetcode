class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int ans = 0;
        for (auto &w : words) {
            if (check(s, w)) ans++;
        }
        return ans;
    }

private:
    bool check(const string &S, const string &W) {
        int i = 0, j = 0, n = S.size(), m = W.size();
        while (i < n && j < m) {
            if (S[i] != W[j]) return false;

            int i1 = i;
            while (i < n && S[i] == S[i1]) i++;
            int j1 = j;
            while (j < m && W[j] == W[j1]) j++;

            int lenS = i - i1;
            int lenW = j - j1;

            if (lenS < lenW) return false; 
            if (lenS < 3 && lenS != lenW) return false; 
        }
        return i == n && j == m;
    }
};
