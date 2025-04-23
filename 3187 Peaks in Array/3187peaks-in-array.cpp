class Solution {
    vector<int> tree;

    bool isPeak(int i, const vector<int>& nums) {
        return i > 0 && i < nums.size() - 1 && nums[i] > nums[i - 1] && nums[i] > nums[i + 1];
    }

    void build(int l, int r, vector<int>& nums, int idx) {
        if (l == r) {
            tree[idx] = isPeak(l, nums) ? 1 : 0;
            return;
        }
        int mid = l + (r - l) / 2;
        build(l, mid, nums, 2 * idx + 1);
        build(mid + 1, r, nums, 2 * idx + 2);
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }

    void pointUpdate(int l, int r, int i, int idx, const vector<int>& nums) {
        if (l == r) {
            tree[idx] = isPeak(i, nums) ? 1 : 0;
            return;
        }
        int mid = l + (r - l) / 2;
        if (i <= mid)
            pointUpdate(l, mid, i, 2 * idx + 1, nums);
        else
            pointUpdate(mid + 1, r, i, 2 * idx + 2, nums);
        tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    }

    int query(int l, int r, int ql, int qr, int idx) {
        if (r < ql || l > qr) return 0;
        if (ql <= l && r <= qr) return tree[idx];
        int mid = l + (r - l) / 2;
        return query(l, mid, ql, qr, 2 * idx + 1) + query(mid + 1, r, ql, qr, 2 * idx + 2);
    }

public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        tree.assign(4 * n, 0);
        build(0, n - 1, nums, 0);

        vector<int> ans;

        for (auto& q : queries) {
            if (q[0] == 1) {
                int left = max(q[1] + 1, 1);
                int right = min(q[2] - 1, n - 2);
                if (left > right) ans.push_back(0);
                else ans.push_back(query(0, n - 1, left, right, 0));
            } else {
                int i = q[1], val = q[2];
                nums[i] = val;
                for (int j = max(1, i - 1); j <= min(n - 2, i + 1); ++j) {
                    pointUpdate(0, n - 1, j, 0, nums);
                }
            }
        }

        return ans;
    }
};
