class fevtree{
    int n;  
    vector<int>tree;
    public: 
    fevtree(int n){
        this->n=n;
        tree.assign(n+1,0);
    }
    void update(int idx,int val){
        for(;idx<=n;idx+=idx &  -idx){
            tree[idx]+=val;
        }
    }
    int query(int idx){
        int sum=0;
        while(idx>0){
            sum+=tree[idx];
            idx-=idx & -idx;
        }
        return sum;
    }
};

class Solution {
public:
    long long minInversionCount(vector<int>& nums, int k) {
        int n=nums.size();
        fevtree tree(n);
        set<int> st(nums.begin(), nums.end());
         map<int,int> mp;
         int rank = 1;
        for (int x : st)
            mp[x] = rank++;
        long long count=0,ans=0;
        for(int i=0;i<k;i++){
            count+=tree.query(n)-tree.query(mp[nums[i]]);
            tree.update(mp[nums[i]],1);
        }
        ans=count;
        // cout<<count<<ans<<endl;
        int l=0;
        for(int i=k;i<n;i++){
            tree.update(mp[nums[l]],-1);
            count-=tree.query(mp[nums[l]]-1);
            count+=tree.query(n)-tree.query(mp[nums[i]]);
            tree.update(mp[nums[i]],1);
            ans=min(ans,count);
            l++;
            // cout<<count<<ans<<endl;
        }
        return ans;
    }
};