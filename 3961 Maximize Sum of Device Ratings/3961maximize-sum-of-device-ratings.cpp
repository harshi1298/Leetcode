class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int m = units.size();
        int n = units[0].size();

        if (n == 1) {
            long long ans = 0;
            for (auto &row : units) {
                ans +=row[0];
            }
            return ans;
        }

        long long sumSecond = 0;
        int globalMin = INT_MAX;
        int minSecond = INT_MAX;

        for (auto &row : units) {
            sort(row.begin(), row.end());

            globalMin = min(globalMin, row[0]);
            minSecond = min(minSecond, row[1]);

            sumSecond += row[1];
        }

        return sumSecond - minSecond + globalMin;
    }
};