class Solution {
private:
    long long solve(string &s,int c1,int c2,int st,int end){
        if(st>end)return 0;
        long long ans=0;
        for(int i=st;i<=end;i++){
            ans+=(s[i]-'0');
        }
        if(ans>0){
            ans=ans*(c1)*(end-st+1);
        }
        else ans=c2;
        if((end-st+1)%2){
            return ans;
        }
        int mid=st+(end-st)/2;
        long long cost1=solve(s,c1,c2,st,mid);
        long long cost2=solve(s,c1,c2,mid+1,end);
        return min(ans,cost1+cost2);
    }
public:
    long long minCost(string s, int encCost, int flatCost) {
        return solve(s,encCost,flatCost,0,s.length()-1);
    }
};