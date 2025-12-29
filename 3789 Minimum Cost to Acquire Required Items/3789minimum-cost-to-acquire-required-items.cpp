class Solution {
long long solve(long long mid,long long cost1,long long cost2,long long costboth,long long need1,long long need2){
    long long ans=0;
    ans+=1ll*mid*costboth;
    ans+=1ll*(max(0ll,need1-mid)*cost1);
    ans+=1ll*(max(0ll,need2-mid)*cost2);
    return ans;
}
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        int high=max(need1,need2);
        int low=0;
        long long ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long l=solve(mid,cost1,cost2,costBoth,need1,need2);
            long long h=solve(mid+1,cost1,cost2,costBoth,need1,need2);
            if(l==h)return l;
            if(l<h){
                ans=l;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};