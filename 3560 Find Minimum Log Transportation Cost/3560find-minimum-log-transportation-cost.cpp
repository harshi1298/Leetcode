class Solution {
public:
    long long minCuttingCost(long long n, long long m, long long k) {
        if(n<=k && m<=k)return 0;
        long long ans=0;
        if(n>k){
            ans+=(k*(n-k));
        }
        else if(m>k){
            ans+=(k*(m-k));
        }
        return ans;
    }
};