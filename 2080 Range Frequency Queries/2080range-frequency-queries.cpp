class RangeFreqQuery {
private:
    vector<unordered_map<int,int>>tree;
    void build(int l,int r,int idx,vector<int>&arr){
        if(l==r){
            tree[idx][arr[l]]++;
            return ;
        }
        int mid=l+(r-l)/2;
        build(l,mid,2*idx+1,arr);
        build(mid+1,r,2*idx+2,arr);
        for(auto [val,count]:tree[2*idx+1]){
            tree[idx][val]+=count;
        }
        for(auto [val,count]:tree[2*idx+2]){
            tree[idx][val]+=count;
        }
    }
    int query(int l,int r,int l1,int r1,int idx,int val){
        if(l>r1 || r<l1)return 0;
        if(l>=l1 && r<=r1){
           return tree[idx][val];
        }
        int mid=l+(r-l)/2;
        return query(l,mid,l1,r1,2*idx+1,val)+query(mid+1,r,l1,r1,2*idx+2,val);
    }
public:
    int n;
    RangeFreqQuery(vector<int>& arr) {
         n=arr.size();
        tree.resize(4*n);
        build(0,n-1,0,arr);
    }
    
    int query(int left, int right, int value) {
        return query(0,n-1,left,right,0,value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */