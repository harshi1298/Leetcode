class Solution {
public:
    vector<long long> countStableSubarrays(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<long long>ans;
        set<int>vis;
        vector<long long >pre(n,1ll);
        for(int i=1;i<n;i++){
            if(nums[i-1]<=nums[i]){
                pre[i]+=pre[i-1];
            }
            else vis.insert(i);
        }
        for(int i=1;i<n;i++){
           pre[i]+=pre[i-1];
        }
        for(auto it : queries){
            int s1=it[0],s2=it[1];
            auto st=vis.lower_bound(s1);
            if(st==vis.end() || *st>s2){
                long long l=s2-s1+1;
                ans.push_back(l*(l+1)/2);
            }
            else{
               long long sub=pre[*st-1];
               long long l=*st-s1;
               ans.push_back(pre[it[1]]-sub+(l*(l+1)/2));
            }
        }
        return ans;
    }
};