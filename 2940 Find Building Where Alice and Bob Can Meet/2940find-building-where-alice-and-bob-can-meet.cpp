class SegmentTree {
private:
    vector<int> tree;

public:
    SegmentTree(int n) {
        tree.resize(4 * n);
    }

    void create(int i, int j, int x, vector<int>& arr) {
        if (i == j) {
            tree[x] = arr[i];
            return;
        }
        int mid = i + (j - i) / 2;
        create(i, mid, 2 * x + 1, arr);
        create(mid + 1, j, 2 * x + 2, arr);
        tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
    }

    int query(int l1,int r1,int l,int r,int i,int maxi) {
        if (r1 < l || l1 > r)
            return -1;
        if(l==r){
            if(tree[i]<=maxi)return -1;
            else return l;
        }
        int mid = l + (r - l) / 2;
        if(l1<=l && r1>=r){
            if(tree[i]<=maxi)return -1;
            else{
                int k;
                k= query(l1,r1,l,mid,2*i+1,maxi);
                if(k==-1) k=query(l1,r1,mid+1,r,2*i+2,maxi);
                return k;
            }
        }
        int k = query(l1,r1,l,mid,2*i+1,maxi);
        if (k == -1) {
            k = query(l1,r1,mid+1,r,2*i+2,maxi);
        }
        return k;
    }
};

class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& h, vector<vector<int>>& q) {
        int n = h.size();
        SegmentTree seg(n);
        seg.create(0, n - 1, 0, h);

        vector<int> ans;
        for (auto &it : q) {
            int i = it[0], j = it[1];
            if (i > j) swap(i, j);
            if (h[i] < h[j] || i==j) {
                ans.push_back(j);
            } else {
                int maxi = h[i];
                int res = seg.query(j, n - 1, 0, n - 1, 0, maxi);
                ans.push_back(res);
            }
        }
        return ans;
    }
};
