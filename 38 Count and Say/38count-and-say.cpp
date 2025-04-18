class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) {
            return "1";
        }
        string str = countAndSay(n - 1);
        string ans = "";
        int count = 1;
        for (int i = 1; i < str.size(); i++) {
            if (str[i] == str[i - 1]) {
                count++;
            } else {
                ans += to_string(count) + str[i - 1];
                count = 1;
            }
        }
        ans += to_string(count) + str.back();
        return ans;
    }
};
