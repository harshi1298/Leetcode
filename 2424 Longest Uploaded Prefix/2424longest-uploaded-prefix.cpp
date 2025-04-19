class LUPrefix {
private:
    vector<int> tree;
    int n;

    void update(int i, int delta) {
        while (i < tree.size()) {
            tree[i] += delta;
            i += (i & -i);
        }
    }

    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= (i & -i);
        }
        return sum;
    }

public:
    LUPrefix(int n) : n(n) {
        tree.resize(n + 2, 0); // 1-based indexing
    }

    void upload(int i) {
        update(i, 1); // mark video i as uploaded
    }

    int longest() {
        int low = 1, high = n, ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (query(mid) == mid) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
