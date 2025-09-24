class Solution {
public:
    string fractionToDecimal(int nu, int de) {
        if (nu == 0) return "0";
        string res;
        if ((nu < 0) ^ (de < 0)) {
            res += '-';
        }
        long long n = abs((long long)nu);
        long long d = abs((long long)de);
        res += to_string(n / d);
        long long rem = n % d;
        if (rem == 0) return res; 
        res += '.';
        unordered_map<long long, int> mpp;
        while (rem != 0) {
            if (mpp.find(rem) != mpp.end()) {
                res.insert(mpp[rem], "(");
                res += ")";
                return res;
            }
            mpp[rem] = res.size();
            rem *= 10;
            res += to_string(rem / d);
            rem %= d;
        }
        return res;
    }
};
