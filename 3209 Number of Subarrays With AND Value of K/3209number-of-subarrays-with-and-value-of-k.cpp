class Solution {
 private:
    vector<int>tree;
    void build(int l,int r,int idx,vector<int>&arr){
        if(l==r){
            tree[idx]=arr[l];
            return ;
        }
        int mid=l+(r-l)/2;
        build(l,mid,2*idx+1,arr);
        build(mid+1,r,2*idx+2,arr);
        tree[idx]=tree[2*idx+1]&tree[2*idx+2];
    }
    int query(int l,int r,int l1,int r1,int idx){
        if(l1>r || r1<l)return INT_MAX;
        if(l1<=l && r1>=r)return tree[idx];
        int mid=l+(r-l)/2;
        return query(l,mid,l1,r1,2*idx+1)&query(mid+1,r,l1,r1,2*idx+2);
    }
    int bs(int i,int n,int t){
        int st=i,end=n;
        int res=end;
        while(st<=end){
            int mid=st+(end-st)/2;
            int val=query(0,n,i,mid,0);
            if(val==t){
                res=mid;
                end=mid-1;
            }
            if(val>t)st=mid+1;
            else end=mid-1;
        }
        return res;
    }
    int bs2(int i,int n,int t){
        int st=i,end=n;
        int res=n;
        while(st<=end){
            int mid=st+(end-st)/2;
            int val=query(0,n,i,mid,0);
            if(val==t){
                res=mid;
                st=mid+1;
            }
            if(val>=t)st=mid+1;
            else end=mid-1;
        }
        return res;
    }
public:
    long long countSubarrays(vector<int>& arr, int target) {
    int n=arr.size();
     tree.resize(4*n);
     build(0,n-1,0,arr);
     long long ans = 0;
      for(int i=0;i<n;i++){
        int l = bs(i, n-1, target);
        int r = bs2(i, n-1, target);
        if (l <= r && l < n && r >= 0) {
            int checkL = query(0, n - 1, i, l, 0);
            int checkR = query(0, n - 1, i, r, 0);
            if (checkL == target && checkR == target) {
                ans += (r - l + 1);
            }
        }
      }
      return ans;
    }
};