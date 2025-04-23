class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> st;
        for (int i = 1; i <= n; i++) {
            int sum = 0, x = i;
            while (x) {
                sum += x % 10;
                x /= 10;
            }
            st[sum]++;
        }
        int maxValue = 0;
        for (const auto& pair : st) {
            if (pair.second > maxValue) {
                maxValue = pair.second;
            }
        }
        int count = 0;
        for (const auto& pair : st) {
            if (pair.second == maxValue) {
                count++;
            }
        }
        return count;
    }
};
