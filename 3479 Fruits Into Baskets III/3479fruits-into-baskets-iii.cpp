class segment{
    vector<int>tree;
    public:
      segment(int n){
        tree.resize(4*n);
      }
      void build(int i,int l,int r,vector<int>&arr){
        if(l==r){
            tree[i]=arr[l];
            return ;
        }
        int mid=l+(r-l)/2;
        build(2*i+1,l,mid,arr);
        build(2*i+2,mid+1,r,arr);
        tree[i]=max(tree[2*i+1],tree[2*i+2]);
      }
      int query(int l1,int r1,int l,int r,int i){
       if(l1 <= l && r <= r1) return tree[i];
        if(r1<l || l1>r){
            return INT_MIN;
        }
        int mid=l+(r-l)/2;
        return max(query(l1,r1,l,mid,2*i+1),query(l1,r1,mid+1,r,2*i+2));
      }

      void update(int idx,int l,int r,int i){
        if(l==r){
            tree[i]=0;
            return ;
        }
        int mid=l+(r-l)/2;
        if(idx <= mid){
           update(idx,l,mid,2*i+1);
        }
        else{
            update(idx,mid+1,r,2*i+2);
        }
        tree[i]=max(tree[2*i+1],tree[2*i+2]);
      }
};
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        segment seg(n);
        seg.build(0,0,n-1,baskets);
        int ans=0;
        for(int i=0;i<n;i++){
            int flag=-1;
            int st=0,end=n-1;
            while(st<=end){
                int mid=st+(end-st)/2;
                if(seg.query(0,mid,0,n-1,0)>=fruits[i]){
                    flag=mid;
                    end=mid-1;
                }
                else {
                    st=mid+1;
                }
            }
            if(flag==-1)ans++;
            else
            seg.update(flag,0,n-1,0);
        }
         return ans;
    }
};
