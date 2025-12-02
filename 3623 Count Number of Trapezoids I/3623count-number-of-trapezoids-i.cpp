class Solution {
private:
    static const long long mod = 1e9 + 7;
public:
    int countTrapezoids(vector<vector<int>>& points) {
        map<int, vector<int>> mapp;
        for (auto &p : points) {
            int x = p[0], y = p[1];
            mapp[y].push_back(x);
        }
        long long total = 0, sum = 0;
        for (auto &it : mapp) {
            auto &v = it.second;
            if (v.size() >= 2) {
                long long e = (long long)v.size() * (v.size() - 1) / 2;
                total = (total + (e % mod) * sum) % mod;
                sum = (sum + (e % mod)) % mod;
            }
        }
        return total;
    }
};
