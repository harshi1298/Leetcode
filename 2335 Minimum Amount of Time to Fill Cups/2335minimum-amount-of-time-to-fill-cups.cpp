class Solution {
public:
    int fillCups(vector<int>& a) {
        int maxi = max({a[0], a[1], a[2]});
        return max(maxi,(a[0]+a[1]+a[2]+1)/2);
    }
};