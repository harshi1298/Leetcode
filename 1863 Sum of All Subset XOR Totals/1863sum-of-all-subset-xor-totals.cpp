class Solution {
private:
    int solve(vector<int>& nums, int i, int XOR) {
        if (i >= nums.size())
            return XOR;
        int taken = solve(nums, i + 1, XOR ^ nums[i]);
        int not_taken = solve(nums, i + 1, XOR);
        return taken + not_taken;
    }

public:
    int subsetXORSum(vector<int>& arr) {
        int n = arr.size();
        int bits = 0;
        for (int i = 0; i < n; ++i)
            bits |= arr[i];
        int ans = bits * pow(2, n - 1);
        return ans;
    }
};