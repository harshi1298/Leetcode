class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            long long sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                int ld=sum%10;
                long long fd=sum;
                while (fd >= 10) fd /= 10;
                if(ld==x && fd==x)ans++;
            }
        }
        return ans;
    }
};