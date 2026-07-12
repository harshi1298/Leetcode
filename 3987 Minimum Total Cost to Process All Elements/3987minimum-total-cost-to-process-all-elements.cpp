class Solution {
int mod=1e9+7;
public:
    int minimumCost(vector<int>& nums, int k) {
        long long total=accumulate(nums.begin(),nums.end(),0ll);
        long long reqop=(total+k-1)/k-1;
        long long ans=(reqop%mod)*((reqop+1)%mod)/2;
        return ans%mod;
    }
};