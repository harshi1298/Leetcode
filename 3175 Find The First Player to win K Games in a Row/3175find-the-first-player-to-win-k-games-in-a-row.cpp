class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        if (k >= n) {
            return max_element(skills.begin(), skills.end()) - skills.begin();
        }

        int prev = 0, count = 0;
        for (int i = 1; ; ++i) {
            int curr = i % n;
            if (curr == prev) continue;

            if (skills[prev] > skills[curr]) {
                count++;
            } else {
                prev = curr;
                count = 1;
            }

            if (count == k) return prev;
        }

        return 0; 
    }
};
