class Segment_Tree {
public:
    vector<int> tree;
    int n;

    Segment_Tree(int size) {
        n = size;
        tree.assign(4 * n, 0);
    }

    void Buildtree(int i, int l, int r, vector<int>& arr) {
        if (l == r) {
            tree[i] = arr[l];
            return;
        }
        int mid = l + (r - l) / 2;
        Buildtree(2 * i + 1, l, mid, arr);
        Buildtree(2 * i + 2, mid + 1, r, arr);
        tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
    }

    void updatetree(int idx, int val, int i, int l, int r) {
        if (l == r) {
            tree[i] = val;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid)
            updatetree(idx, val, 2 * i + 1, l, mid);
        else
            updatetree(idx, val, 2 * i + 2, mid + 1, r);
        tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
    }

    int query(int l1, int r1, int l, int r, int i) {
        if (r1 < l || l1 > r)
            return 0;
        if (l1 <= l && r <= r1)
            return tree[i];
        int mid = l + (r - l) / 2;
        return query(l1, r1, l, mid, 2 * i + 1) + query(l1, r1, mid + 1, r, 2 * i + 2);
    }
};

class NumArray {
private:
    Segment_Tree seg;
    int n;

public:
    NumArray(vector<int>& nums) : seg(nums.size()), n(nums.size()) {
        seg.Buildtree(0, 0, n - 1, nums);
    }

    void update(int index, int val) {
        seg.updatetree(index, val, 0, 0, n - 1);
    }

    int sumRange(int left, int right) {
        return seg.query(left, right, 0, n-1, 0);
    }
};
