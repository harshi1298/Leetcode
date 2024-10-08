class Solution {
private:
    int solve1(vector<int> nums, int index, vector<int>& dp) {
        // cout<<index<<"  "<<nums.size()<<endl;
        if (index >= nums.size())
            return 0;
        if (dp[index] != -1)
            return dp[index];
        int l = solve1(nums, index + 1, dp);
        int r = nums[index] + solve1(nums, index + 2, dp);
        // cout<<l<<" "<<r<<"  "<<index<<endl;
        return dp[index] = max(l, r);
    }

    int solve(vector<int> nums, int index, vector<int>& dp) {
        if (index >= nums.size() - 1)
            return 0;
        if (dp[index] != -1)
            return dp[index];
        int l = solve(nums, index + 1, dp);
        int r = nums[index] + solve(nums, index + 2, dp);
        return dp[index] = max(l, r);
    }

public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        vector<int> dp(nums.size(), -1);
        vector<int> dp1(nums.size(), -1);
        int l = solve(nums, 0, dp);
        int r = solve1(nums, 1, dp1);
        return max(l, r);
    }
};