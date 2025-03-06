class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long sum = 0, sqrtsum = 0;
        for (auto item : grid) {
            for(auto v:item){
                sum += v;
            sqrtsum += (long long)v * v;
            }
        }
        long long k = grid.size()*grid.size();
        long long t1 = k * (k + 1) / 2;
        long long t2 = k * (k + 1) * (2 * k + 1) / 6;
        long long diffSum = t1 - sum; 
        long long diffSqrtsum = t2 - sqrtsum;
        long long sumMissingAndRepeated = diffSqrtsum / diffSum;
        int missing = (diffSum + sumMissingAndRepeated) / 2;
        int repeated = missing - diffSum;
        
        return {repeated, missing};
    }
};