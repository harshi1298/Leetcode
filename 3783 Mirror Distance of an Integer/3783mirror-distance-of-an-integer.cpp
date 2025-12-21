class Solution {
public:
    int mirrorDistance(int n) {
        string k=to_string(n);
        reverse(k.begin(),k.end());
        long long l=stoll(k);
        return abs(l-1ll*n);
    }
};