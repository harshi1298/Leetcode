class Seg{
vector<int>tree;
public:
    Seg(int n){
        tree.resize(4*(n));
    }
    void update(int node,int l,int r,int idx,int val){
        if(l==r){
            tree[node]=val;
            return ;
        }
        int mid=l+(r-l)/2;
        if(idx<=mid){
            update(2*node+1,l,mid,idx,val);
        }
        else{
            update(2*node+2,mid+1,r,idx,val);
        }
        tree[node] = max(tree[2*node+1], tree[2*node+2]);
    }
    int query(int node,int l,int r,int st,int end){
        if(end<l || r<st)return INT_MIN;
        if(l<=st && end<=r)return tree[node];
        int mid=st+(end-st)/2;
        int left=query(2*node+1,l,r,st,mid);
        int right=query(2*node+2,l,r,mid+1,end);
        return max(left,right);
    }
};
class Solution { 
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int ans=0;
        int maxi=*max_element(nums.begin(),nums.end());
        Seg seg(maxi+1);
        for(int i=0;i<nums.size();i++){
            int l=max(0,nums[i]-k);
            int ele=seg.query(0,l,nums[i]-1,0,maxi);
            ans=max(ans,ele+1);
            seg.update(0,0,maxi,nums[i],ele+1);
        }
        return ans;
    }
};