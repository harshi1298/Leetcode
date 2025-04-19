class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int ans = 0;

        for (int j = 0; j < n; ++j) {
            int ls = 0, lg = 0;
            int rs = 0, rg = 0;

            for (int i = 0; i < j; ++i) {
                if (rating[i] < rating[j]) ls++;
                if (rating[i] > rating[j]) lg++;
            }
            for (int k = j + 1; k < n; ++k) {
                if (rating[k] < rating[j]) rs++;
                if (rating[k] > rating[j]) rg++;
            }

            ans += ls * rg + lg * rs;
        }

        return ans;
    }
};
