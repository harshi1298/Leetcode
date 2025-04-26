class Solution {
private:
    vector<int> buildLPS(string& pattern) {
        int n = pattern.size();
        vector<int> lps(n, 0);
        int len = 0;
        for (int i = 1; i < n;) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    void strStr(string s, string p, vector<int>& arr) {
        if (p.empty())
            return;
        vector<int> lps = buildLPS(p);
        int i = 0, j = 0;
        int n = s.size(), m = p.size();
        while (i < n) {
            if (s[i] == p[j]) {
                i++;
                j++;
            }
            if (j == m) {
                arr[i - j + 1]++;
                if (i + 1 < arr.size())
                    arr[i + 1]--;
                j = lps[j - 1];
            } else if (i < n && s[i] != p[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
    }

public:
    int countCells(vector<vector<char>>& grid, string pattern) {
        int row = grid.size(), col = grid[0].size();
        string str1, str2;

        vector<int> arr(row * col + 2, 0);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                str1.push_back(grid[i][j]);
            }
        }
        strStr(str1, pattern, arr);

        vector<int> arr2(row * col + 2, 0);
        for (int j = 0; j < col; j++) {
            for (int i = 0; i < row; i++) {
                str2.push_back(grid[i][j]);
            }
        }
        strStr(str2, pattern, arr2);
        int prev1=0,prev2=0;
        for (int i = 1; i <= row * col; i++) {
            prev1+= arr[i];
            if(prev1>0) arr[i]=1;
            else arr[i]=0;
            prev2 += arr2[i];
            if(prev2>0) arr2[i]=1;
            else arr2[i]=0;
        }

        vector<vector<int>> temp(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                temp[i][j] += arr[i * col + j + 1];
                temp[i][j] += arr2[j * row + i + 1];
            }
        }

        int ans = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (temp[i][j] >= 2) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
