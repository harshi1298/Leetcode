class Solution {
    const double EPS = 1e-6;
    const double TARGET = 24.0;

    bool solve(vector<double> nums) {
        int n = nums.size();
        if (n == 1) return fabs(nums[0] - TARGET) < EPS;

        // Try all pairs of numbers
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                // Pick nums[i] and nums[j]
                vector<double> next;
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j) next.push_back(nums[k]);
                }

                // Try all 4 operations
                for (int op = 0; op < 4; op++) {
                    if (op == 0) next.push_back(nums[i] + nums[j]);
                    if (op == 1) next.push_back(nums[i] - nums[j]);
                    if (op == 2) next.push_back(nums[i] * nums[j]);
                    if (op == 3 && fabs(nums[j]) > EPS) next.push_back(nums[i] / nums[j]);
                    
                    if (solve(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }

public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return solve(nums);
    }
};
