class Solution {
private:
    int findidx(vector<int>&arr,int i,int num){
        int n=arr.size();
        int st=i+1,end=n-1,ans=i;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(arr[mid]<num){
               ans=mid;
               st=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            ans[i]=maxi;
        }
        for(int i=n-2;i>=0;i--){
            nums[i]=min(nums[i],nums[i+1]);
        }
        // for(auto it : ans)cout<<it<<" ";
        // cout<<endl;
        // for(auto it : nums)cout<<it<<" ";
        for(int i=n-1;i>=0;i--){
            int k=findidx(nums,i,ans[i]);
            ans[i]=max(ans[i],ans[k]);
        }
        return ans;
    }
};