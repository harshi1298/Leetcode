class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int ans=arr[0];
        int  n=arr.size();
        vector<int>pre(n),suff(n);
        int sum=arr[0];
        pre[0]=sum;
        for(int i=1;i<n;i++){
           sum+=arr[i];
           sum=max(sum,arr[i]);
           pre[i]=sum;
           ans=max(ans,sum);
        }
        sum=arr[n-1];
        suff[n-1]=sum;
        for(int i=n-2;i>=0;i--){
            sum+=arr[i];
            sum=max(sum,arr[i]);
            suff[i]=sum;
            ans=max(ans,sum);
        }
        for(int i=1;i<n-1;i++){
            ans=max(ans,max({pre[i-1]+suff[i+1],pre[i-1],suff[i+1]}));
        }
        return ans;
    }
}; 