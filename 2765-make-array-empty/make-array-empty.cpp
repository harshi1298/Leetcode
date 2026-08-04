class Solution {
private:
    vector<long long> tree;

    void update(int i, int val) {
        while (i < tree.size()) {
            tree[i] += val;
            i += (i & -i);
        }
    }

    long long query(int i) {
        long long ans = 0;

        while (i > 0) {
            ans += tree[i];
            i -= (i & -i);
        }

        return ans;
    }

public:
    long long countOperationsToEmptyArray(vector<int>& nums) {
        vector<pair<int, int>> arr;
        int n = nums.size();

        tree.resize(n + 2, 0);

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        long long ans = 0;

        // Number of elements processed so far
        long long removed = 0;

        // Position from where we start scanning
        int prev = 0;

        for (int i = 0; i < n; i++) {

            int curr = arr[i].second + 1;

            if (curr >= prev) {
                // No circular wrap
                ans += (curr - prev) - 
                       (query(curr) - query(prev));
            } 
            else {
                // Circular wrap
                ans += (n - prev) - 
                       (query(n) - query(prev));

                ans += curr - query(curr);
            }

            // Mark current element as removed
            update(curr, 1);

            prev = curr;
        }

        return ans;
    }
};