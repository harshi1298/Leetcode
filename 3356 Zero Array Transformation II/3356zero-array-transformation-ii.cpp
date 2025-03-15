class Solution {
private:
    bool isvalid(vector<int>nums, vector<vector<int>>& q,int mid){
        int n=nums.size();
        vector<int>diff(n+1,0);
        for(int i=0;i<mid;i++){
            diff[q[i][0]]+=q[i][2];
            diff[q[i][1]+1]-=q[i][2];
        }
        for(int i=1;i<=n;i++)diff[i]+=diff[i-1];
        for(int i=0;i<n;i++){
            if(nums[i]-diff[i]>0)return false;
        }
        return true;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int mini=0,maxi=queries.size(),ans=-1;
        while(mini<=maxi){
            int mid=mini+(maxi-mini)/2;
            if(isvalid(nums,queries,mid)){
                ans=mid;
                maxi=mid-1;
            }
            else mini=mid+1;
        }
        return ans;
    }
};