class Solution {
private:
   int ans=0;
   void merge(vector<int>&nums,int i,int mid,int j){
    vector<long long>temp1(mid-i+1);
    vector<long long>temp2(j-mid);
    for(int k=i;k<=mid;k++)temp1[k-i]=nums[k];
    for(int k=mid+1;k<=j;k++)temp2[k-mid-1]=nums[k];
    int n = 0;
       for (int m = 0; m < temp1.size(); m++) {
           while (n < temp2.size() && temp1[m] > 2 * temp2[n]) {
               n++;
           }
           ans += n; 
       }
    int l1=0,l2=0,k=i;
    while(l1<temp1.size() && l2<temp2.size()){
       if(temp1[l1]>temp2[l2]){
          nums[k++]=temp2[l2++];
       }
       else{
          nums[k++]=temp1[l1++]; 
       }
    }
    while(l1<temp1.size()){
      nums[k++]=temp1[l1++];
    }
    while(l2<temp2.size()){
      nums[k++]=temp2[l2++];
    }
   }
   void solve(vector<int>&nums,int i,int j){
       if(i>=j)return;
       int mid=i+(j-i)/2;
       solve(nums,i,mid);
       solve(nums,mid+1,j);
       merge(nums,i,mid,j);
   }
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        solve(nums,0,n-1);
        for(auto it:nums)cout<<it<<" ";
        return ans;
    }
};