const int MOD = 1e9 + 7;
const int MAXN = 100000;
class Solution {
public:
    long long fact[MAXN + 1], invFact[MAXN + 1];
    long long power(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    void precompute() {
        fact[0] = 1;
        for (int i = 1; i <= MAXN; i++)
            fact[i] = fact[i - 1] * i % MOD;
    
        invFact[MAXN] = power(fact[MAXN], MOD - 2);
    
        for (int i = MAXN - 1; i >= 0; i--)
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }

    long long nCr(int n, int r) {
        if (r > n || r < 0) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }
    int countVisiblePeople(int n, int pos, int k) {
        precompute(); 
        return (nCr(n-1,k)*2)%MOD;
    }
};