class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        vector<string> words2 = words;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            swap(words2[i][0], words2[i][1]);
        }

        unordered_map<string, int> mapp;
        for (int i = 0; i < n; i++) {
            mapp[words[i]]++;
        }

        int ans = 0;
        bool flag = false;

        for (int i = 0; i < n; i++) {
            string word = words[i];
            string rev = words2[i];

            if (mapp[word] == 0) continue; 
            if (word == rev) {
                int pairs = mapp[word] / 2;
                ans += pairs * 4;
                mapp[word] -= pairs * 2;
                if (mapp[word] > 0) flag = true; 
            } else if (mapp.find(rev) != mapp.end() && mapp[rev] > 0) {
                int pairCount = min(mapp[word], mapp[rev]);
                ans += pairCount * 4;
                mapp[word] -= pairCount;
                mapp[rev] -= pairCount;
            }
        }

        if (flag) ans += 2;

        return ans;
    }
};
