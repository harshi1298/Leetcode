class Solution {
public:
    int minimumDeletions(string word, int k) {
        int n = word.size();  
        unordered_map<char, int> mapp;
        for (int i = 0; i < n; i++) {
            mapp[word[i]]++;
        }

        vector<int> temp;
        for (auto [c, f] : mapp) temp.push_back(f);

        sort(temp.begin(), temp.end());
        int ans = INT_MAX;
        int size = temp.size();
        
        vector<int> suffsum(size);
        suffsum[size - 1] = temp[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            suffsum[i] = suffsum[i + 1] + temp[i];
        }

        int total = accumulate(temp.begin(), temp.end(), 0);

        for (int i = 0; i < size; i++) {
            int upper = upper_bound(temp.begin(), temp.end(), temp[i] + k) - temp.begin();
            int del_high = (upper < size) ? suffsum[upper] - (size - upper) * (temp[i] + k) : 0;
            int del_low = (i > 0) ? suffsum[0] - suffsum[i] : 0;
            ans = min(ans, del_low + del_high);
        }

        return ans;
    }
};
