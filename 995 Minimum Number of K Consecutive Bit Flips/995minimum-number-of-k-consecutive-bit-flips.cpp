class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>diff(n+1,0);
        int temp=0;
        int ans=0;
        for(int i=0;i<=n-k;i++){
           temp=temp+diff[i];
           if(nums[i]==0 && (temp)%2==0){
            diff[i]++;
            diff[i+k]--;
            ans++;
            temp++;
           }
            if(nums[i]==1 && (temp)%2==1){
            diff[i]++;
            diff[i+k]--;
            ans++;
            temp++;
           }
        }
        for(int i=n-k+1;i<n;i++){
            temp=temp+diff[i];
            cout<<nums[i]<<" ";
            if(temp%2)nums[i]=!nums[i];
            cout<<nums[i]<<endl;
            if(nums[i]==0)return -1;
        }
        return ans;
    }
};