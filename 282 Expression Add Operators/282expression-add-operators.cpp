class Solution {
private:
    void solve(string& num, long long i, long long sum, long long prev,
               string temp, long long t, unordered_set<string>& ans) {
        if (i >= num.length()) {
            if (t == sum) {
                ans.insert(temp);
            }
            return;
        }
        for (long long j = i; j < num.length(); ++j) {
            if (i!=j && num[i] == '0') {
                break;
            }
            string currNum = num.substr(i, j - i + 1);
            long long currVal = stoll(currNum);
            if (i == 0) {
                solve(num, j + 1, currVal, currVal, currNum, t, ans);
            } else {
                solve(num, j + 1, sum + currVal, currVal, temp + "+" + currNum,
                      t, ans);
                solve(num, j + 1, sum - currVal, -currVal, temp + "-" + currNum,
                      t, ans);
                solve(num, j + 1, sum - prev + prev * currVal, prev * currVal,
                      temp + "*" + currNum, t, ans);
            }
        }
    }

public:
    vector<string> addOperators(string num, long long target) {
        unordered_set<string> ans;
        if (num.empty())
            return {};
        solve(num, 0, 0, 0, "", target, ans);
        return vector<string>(ans.begin(), ans.end());
    }
};