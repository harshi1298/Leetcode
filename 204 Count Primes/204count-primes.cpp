class Solution {
public:
    int countPrimes(int n) {
        if(n==0)return 0;
        vector<int>isprime(n+1,1);
        isprime[0]=isprime[1]=0;
        for(int i=2;i<n;i++){
            if(isprime[i]){
                for(long long j=1ll*i*i;j<n;j+=i){
                    isprime[j]=0;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(isprime[i])ans++;
        }
        return ans;
    }
};