class Solution {
public:
    long long maxGCDScore(vector<int>& nums, int k) {
        long long ans=1;
        int n=nums.size();
        vector<int>count(n);
        for(int i=0;i<n;i++){
            int temp=nums[i];
            while(temp%2==0){
                count[i]++;
                temp/=2;
            }
        }
        for(int i=0;i<n;i++){
            int minic=0,minnum=32;
            long long temp=nums[i];
            for(int j=i;j<n;j++){
                if(count[j]<minnum){
                    minnum=count[j];
                    minic=1;
                }
                else if(count[j]==minnum)minic++;
                temp=gcd(temp,nums[j]);
                long long l=j-i+1;
                if(minic<=k){
                    ans=max(ans,l*temp*2);
                }
                else ans=max(ans,l*temp);
            }  
        }
        return ans;
    }
};