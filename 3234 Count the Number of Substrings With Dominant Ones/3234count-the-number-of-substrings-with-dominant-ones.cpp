class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> pre(n, 0);
        pre[0] = (s[0] == '1' ? 1 : 0);
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + (s[i] == '1' ? 1 : 0);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                int one = pre[j] - (i - 1 >= 0 ? pre[i - 1] : 0);
                int zero = (j - i + 1 - one);

                if (zero * zero > one) {
                    j += (zero * zero - one - 1);
                }
                else if (zero * zero == one) {
                    res++;
                }
                else {
                    res++;
                    int k = (sqrt(one) - zero);
                    int next=j + k;
                    if (next >= n) {
                        res += (n - j - 1);
                        break;
                    } else {
                        res += k;
                    }
                    j=next;
                }
            }
        }
        return res;
    }
};
