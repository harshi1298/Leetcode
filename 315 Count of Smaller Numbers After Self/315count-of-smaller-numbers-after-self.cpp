class Solution {
private:
    vector<int>tree;
    void update(int i){
        while(i<tree.size()){
            tree[i]+=1;
            i+=(i&-i);
        }
    }
    int query(int i){
        int ans=0;
        while(i>0){
           ans+=tree[i];
           i-=(i&-i);
        }
        return ans;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        tree.resize(maxi-mini+2);
        vector<int>ans(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
           ans[i]=query(nums[i]-mini);
           update(nums[i]-mini+1);
        }
        return ans;
    }
};