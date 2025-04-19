class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        int n = queries.size();
        int size = n + m + 2;  
        vector<int> BIT(size, 0);
        vector<int> pos(m + 1); 
        for (int i = 1; i <= m; i++) {
            pos[i] = n + i;
            update(BIT, pos[i], 1);
        }
        vector<int> result;
        for (int i = 0; i < n; i++) {
            int val = queries[i];
            int p = pos[val];
            result.push_back(query(BIT, p) - 1);
            update(BIT, p, -1);
            pos[val] = n - i;
            update(BIT, pos[val], 1);
        }
        return result;
    }

private:
    void update(vector<int>& BIT, int i, int delta) {
        while (i < BIT.size()) {
            BIT[i] += delta;
            i += (i & -i);
        }
    }

    int query(vector<int>& BIT, int i) {
        int sum = 0;
        while (i > 0) {
            sum += BIT[i];
            i -= (i & -i);
        }
        return sum;
    }
};
