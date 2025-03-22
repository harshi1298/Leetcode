class Solution {
private:
    // Compute combination nCk % p for small p (either 2 or 5)
    long long C(long long n, long long k, int mod) {
        if (k == 0 || k == n) return 1;
        if (mod == 2) {
            // Modulo 2 behavior: C(n, k) % 2 is 1 if n % 2 == k % 2, else 0
            return (n % 2 == k % 2) ? 1 : 0;
        }
        if (mod == 5) {
            long long result = 1;
            for (long long i = 0; i < k; ++i) {
                result = (result * (n - i)) % mod;
                result = (result * modInverse(i + 1, mod)) % mod;
            }
            return result;
        }
        return 0;
    }

    // Modular inverse using Fermat's Little Theorem for mod 5
    long long modInverse(long long a, int mod) {
        long long result = 1;
        long long exp = mod - 2;  // Fermat's Little Theorem
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * a) % mod;
            }
            a = (a * a) % mod;
            exp /= 2;
        }
        return result;
    }

    // Lucas' Theorem: Calculate C(n, k) % p for a given prime p (either 2 or 5)
    long long comboLucas(long long n, long long k, int mod) {
        long long result = 1;
        while (n > 0 || k > 0) {
            long long n_mod = n % mod;
            long long k_mod = k % mod;
            if (k_mod > n_mod) return 0; // If k > n for any digit, return 0
            result = (result * C(n_mod, k_mod, mod)) % mod;
            n /= mod;
            k /= mod;
        }
        return result;
    }

    // Chinese Remainder Theorem: Combine results modulo 2 and 5 to modulo 10
    long long combineCRT(long long x2, long long x5) {
        long long mod = 10;
        long long result = 0;
        long long m1 = 5, m2 = 2;
        long long inv_m1 = modInverse(m1, m2);  // Inverse of 5 mod 2 is 1
        long long inv_m2 = modInverse(m2, m1);  // Inverse of 2 mod 5 is 3

        result = (x2 * m1 * inv_m1 + x5 * m2 * inv_m2) % mod;
        return (result + mod) % mod;
    }

public:
    bool hasSameDigits(string s) {
        int n = s.length();
        int temp1 = 0, temp2 = 0;
        for (int i = 0; i < n; i++) {
            int l = s[i] - '0';
            // Compute temp1 and temp2 with Lucas' Theorem
            if (i < n - 1) {
                long long comb2 = comboLucas(n - 2, i, 2);
                long long comb5 = comboLucas(n - 2, i, 5);
                temp1 = (temp1 + l * combineCRT(comb2, comb5)) % 10;
            }
            if (i > 0) {
                long long comb2 = comboLucas(n - 2, i - 1, 2);
                long long comb5 = comboLucas(n - 2, i - 1, 5);
                temp2 = (temp2 + l * combineCRT(comb2, comb5)) % 10;
            }
        }

        return temp1 == temp2;
    }
};