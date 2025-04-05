class Solution {
private:
    long long ispossible(vector<int>&nums1,vector<int>&nums2,long long mid,long long k){
        long long count=0;
        long long size1=nums1.size(),size2=nums2.size();
        for(int i=0;i<size1;i++){
           if(nums1[i]<0){
              long long t=ceil((double)mid/nums1[i]);
              long long k=lower_bound(nums2.begin(),nums2.end(),t)-nums2.begin();
              count+=(size2-k);
           }
           else if(nums1[i]>0){
              long long t=floor((double)mid/nums1[i]);
              long long k=upper_bound(nums2.begin(),nums2.end(),t)-nums2.begin();
              count+=(k);
           }
           else{
            if(mid>=0){
                    count += size2;
                }
           }
        }
        if(count>=k)return true;
        return false;
    }
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long start=-1e10,end=1e10;
        long long ans=0;
        while(start<=end){
            long long mid=start+(end-start)/2;
            if(ispossible(nums1,nums2,mid,k)){
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
};