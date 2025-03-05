class Solution {
public:
    long long coloredCells(int n) {
        long long ans=(long long)(n-1)*(long long)(n-1)*2+(long long)(2*n-1);
        return ans;
    }
};