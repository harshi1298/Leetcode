class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        long long ans=0;
        int i=0,n=s.length();
        while(i<n && s[i]=='1'){
            ans+=nums[i];
            i++;
        }
        for(;i<n;i++){
            if(s[i]=='1'){
                long long pos=nums[i-1];
                long long neg=nums[i-1];
                while(i<n && s[i]=='1'){
                    pos+=nums[i];
                    neg=min(neg,1ll*nums[i]);
                    i++;
                }
                ans+=pos-neg;
            }
        }
        return ans;
    }
};