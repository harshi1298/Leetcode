class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        long long ans=0;
        long long d=0,n=arr.size();
        for(int i=0;i<n;i++){
            d+=abs(brr[i]-arr[i]);
        }
        sort(arr.begin(),arr.end());
        sort(brr.begin(),brr.end());
        for(int i=0;i<n;i++){
            ans+=abs(brr[i]-arr[i]);
        }
        return min(ans+k,d);
    }
};