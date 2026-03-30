class Solution {
private:
    int mod=1e9+7;
    int power(long long a,long long b){
        long long ans=1;
        while(b){
            if(b&1){
                ans=ans*a%mod;
            }
            a=a*a%mod;
            b/=2;
        }
        return ans;
    }
    int ncr(int n,int r){
        long long num=1,den=1;
        for(int i=0;i<r;i++){
            num=num*(n-i)%mod;
            den=den*(i+1)%mod;
        }
        return num*power(den,mod-2)%mod;
    }
public:
    int numberOfWays(int st, int end, int k) {
        if(st>end)return numberOfWays(end,st,k);
        int d=abs(st-end);
        if(d>k || (k+d)%2)return 0;
        return ncr(k,(k+d)/2);

    }
};