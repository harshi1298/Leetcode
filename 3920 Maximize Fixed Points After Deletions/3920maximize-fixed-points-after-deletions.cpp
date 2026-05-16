class Solution {
private:
    int solve(int idx,int i,vector<int>&nums,vector<vector<int>>&dp){
        if(idx>=nums.size())return 0;
        if(dp[idx][i]!=-1)return dp[idx][i];
        int ans=0;
        if(nums[idx]!=i){
            ans= max(solve(idx+1,i+1,nums,dp),solve(idx+1,i,nums,dp));
        }
        else{
            ans=max(1+solve(idx+1,i+1,nums,dp),solve(idx+1,i,nums,dp));
        }
        return dp[idx][i]=ans;
    }
public:
        int maxFixedPoints(vector<int>& A) {
        vector<int> s;
        vector<pair<int, int>> B;
        for (int i = 0; i < A.size(); ++i) {
            if (i >= A[i]) {
                B.push_back({i - A[i], A[i]});
            }
        }
        sort(B.begin(), B.end());
        for (auto& p : B) {
            int x = p.second;
            auto it = lower_bound(s.begin(), s.end(), x);
            if (it == s.end()) {
                s.push_back(x);
            } else {
                *it = x;
            }
        }
        return s.size();
    }
};