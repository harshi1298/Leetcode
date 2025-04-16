class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> mapp;
        int l = 0, r = 0, n = nums.size();
        long long ans = 0, count = 0;
        while (r < n) {
            count += mapp[nums[r]];
            mapp[nums[r]]++;
            while (count >= k) {
                if (count >= k) {
                    ans += (n - r);
                }
                count -= (mapp[nums[l]] - 1);
                mapp[nums[l]]--;
                l++;
            }
            r++;
            // cout << r << " " << ans << " " << count << endl;
        }
        return ans;
    }
};