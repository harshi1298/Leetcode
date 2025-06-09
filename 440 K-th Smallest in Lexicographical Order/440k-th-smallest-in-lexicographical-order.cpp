class Solution {
private:
    int totalc(int n, long long first, long long second) {
        int total = 0;
        while (first <= n) {
            total += min(n + 1LL, second) - first;
            first *= 10;
            second *= 10;
        }
        return total;
    }

public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;

        while (k > 0) {
            int step = totalc(n, curr, curr + 1);
            if (step <= k) {
                k -= step;
                curr += 1;
            } else {
                k--;
                curr *= 10;
            }
        }

        return curr;
    }
};
