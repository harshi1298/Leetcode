class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<bool> ans;
        vector<char> can(k+1, 0);
        can[0] = 1;
        int rem1 = 0; 
        for (int st=0; st<n; st++) {
            while (rem1 < n && nums[rem1] <= st+1) {
                int val = nums[rem1];
                for (int j=k; j>=val; j--) {
                    if (can[j-val]) can[j] = 1;
                }
                rem1++;
            }
            int leftover = n - rem1;
            bool ok = false;
            for (int j=0; j<=k; j++) {
                if (can[j]) {
                    int need = k - j;
                    if (need % (st+1) == 0 && need / (st+1) <= leftover) {
                        ok = true;
                        break;
                    }
                }
            }
            ans.push_back(ok);
        }
        return ans;
    }
};
