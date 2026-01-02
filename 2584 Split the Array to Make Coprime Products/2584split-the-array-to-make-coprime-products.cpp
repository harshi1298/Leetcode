class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        unordered_map<int, pair<int,int>> mp;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int temp = nums[i];

            for (int p = 2; p * p <= temp; p++) {
                if (temp % p == 0) {
                    int first = i;
                    while (temp % p == 0) temp /= p;

                    if (!mp.count(p)) mp[p] = {i, i};
                    else mp[p].second = i;
                }
            }
            if (temp > 1) {
                if (!mp.count(temp)) mp[temp] = {i, i};
                else mp[temp].second = i;
            }
        }

        vector<int> diff(n + 1, 0);

        for (auto &[prime, range] : mp) {
            diff[range.first]++;
            diff[range.second]--;
        }

        int active = 0;
        for (int i = 0; i < n - 1; i++) {
            active += diff[i];
            if (active == 0) return i;
        }

        return -1;
    }
};
