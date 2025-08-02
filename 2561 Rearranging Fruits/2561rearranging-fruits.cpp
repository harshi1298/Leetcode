class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        unordered_map<int,int> mapp1, mapp2;
        for (int i = 0; i < b1.size(); ++i) {
            mapp1[b1[i]]++;
            mapp2[b2[i]]++;
        }

        vector<int> temp1, temp2;
        unordered_set<int> keys;
        for (auto& p : mapp1) keys.insert(p.first);
        for (auto& p : mapp2) keys.insert(p.first);

        for (int key : keys) {
            int val1 = mapp1[key];
            int val2 = mapp2[key];

            if ((val1 + val2) % 2 != 0) return -1;

            int diff = val1 - val2;
            if (diff > 0) {
                for (int i = 0; i < diff / 2; ++i) temp1.push_back(key);
            } else if (diff < 0) {
                for (int i = 0; i < (-diff) / 2; ++i) temp2.push_back(key);
            }
        }

        int mini = min(*min_element(b1.begin(), b1.end()), *min_element(b2.begin(), b2.end()));
        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());

        long long ans = 0;
        int j=temp1.size()-1;
        for (int i = 0; i < temp1.size(); ++i) {
            ans += min({temp1[i], temp2[j-i], 2 * mini});
        }

        return ans;
    }
};
