class Solution {
private:
    long long modulo = 1e9 + 7;
    vector<long long> factorial, invFactorial;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = res * a % modulo;
            a = a * a % modulo;
            b >>= 1;
        }
        return res;
    }

    void precomputeFactorials(int n) {
        factorial.resize(n + 1);
        invFactorial.resize(n + 1);
        factorial[0] = 1;
        for (int i = 1; i <= n; ++i)
            factorial[i] = factorial[i - 1] * i % modulo;
        invFactorial[n] = modPow(factorial[n], modulo - 2);
        for (int i = n - 1; i >= 0; --i)
            invFactorial[i] = invFactorial[i + 1] * (i + 1) % modulo;
    }

    long long comb(int n, int k) {
        if (k > n || k < 0) return 0;
        return factorial[n] * invFactorial[k] % modulo * invFactorial[n - k] % modulo;
    }
    int solve(int i,int prev,int n,int maxi,vector<vector<int>>&dp){
         if(i==n)return 1;
         bool flag=0;
         long long ans=0;
         if(dp[i][prev]!=-1)return dp[i][prev];
         for(int j=prev*2;j<=maxi;j+=prev){
            ans+=(solve(i+1,j,n,maxi,dp));
            ans%=modulo;
            if(j+prev>maxi){
                ans+=(comb(n-1,i-1));
                ans%=modulo;
                flag=1;
            }
         }
        if(!flag){
             if(prev*2>maxi){
                ans+=(comb(n-1,i-1));
                ans%=modulo;
            }
        }
        return dp[i][prev]=ans;
    }
public:
    int idealArrays(int n, int maxi) {
        precomputeFactorials(n);
        long long ans = 0;
        vector<vector<int>> dp(20, vector<int>(maxi + 1, -1));
        for(int i=1;i<=maxi;i++){
            ans+=(solve(1,i,n,maxi,dp));
            ans%=modulo;
        }
        return ans;
    }
};
