class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int j = 0;  // write pointer
        int ans = 0;
        int count = 1;

        for (int i = 1; i <= n; i++) {
            if (i < n && chars[i] == chars[i - 1]) {
                count++;
            } else {
                chars[j++] = chars[i - 1];
                ans++;
                if (count > 1) {
                    int temp = 0;
                    int c = count;
                    while (c) {
                        chars[j++] = (c % 10 + '0');
                        c /= 10;
                        temp++;
                    }
                    reverse(chars.begin() + j - temp, chars.begin() + j);
                    ans += temp;
                }

                count = 1;
            }
        }

        return ans;
    }
};
