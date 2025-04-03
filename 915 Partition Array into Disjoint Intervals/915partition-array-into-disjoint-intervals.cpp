class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
      int n=nums.size(),ans=0;
        vector<int>pre(n+1);
        for(int i=1;i<=n;i++){
           pre[i]=max(pre[i-1],nums[i-1]);
        }
        vector<int>suff(n+1);
        suff[n]=INT_MAX;
        for(int i=n-1;i>0;i--){
            suff[i]=min(suff[i+1],nums[i]);
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            if(maxi<=suff[i+1])return i+1;
        }  
        return -1;
    }
};