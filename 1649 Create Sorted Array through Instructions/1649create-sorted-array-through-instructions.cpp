class Solution {
private:
    int mod=1e9+7;
    vector<int>tree;
    void update(int i){
        while(i<tree.size()){
            tree[i]+=1;
            i+=(i&-i);
        }
    }
   long long  query(int i){
        int ans=0;
        while(i>0){
            ans+=tree[i];
            i-=(i&-i);
        }
        return ans;
    }
public:
    int createSortedArray(vector<int>& ins) {
        int maxi=*max_element(ins.begin(),ins.end());long long ans=0;
        tree.resize(maxi+1);
        int n=ins.size();
        for(int i=0;i<n;i++){
           long long k=min(query(ins[i]-1),(query(maxi)-query(ins[i])));
           ans+=k;
           ans=ans%mod;
           update(ins[i]);
        }
        return ans;
    }
};