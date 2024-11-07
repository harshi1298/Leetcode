class Solution {
public:
    long long maxScore(vector<int>& nums) {
        if(nums.size()==1)return nums[0]*nums[0];
        long long ans=0;
      for(int i=0;i<nums.size();i++){
          long long mul1 = i!=0?nums[0]:nums[1];
          for(int j=0;j<nums.size();j++){
              if(i!=j){
                long long k = mul1 * nums[j];
                long long m = gcd(mul1, nums[j]);
                mul1 = k / m;
                }
          }
          int hcf=i!=0?nums[0]:nums[1];
          for(int j=0;j<nums.size();j++){
              if(i!=j){
                  hcf=gcd(hcf,nums[j]);
            }
          }
          ans=max(ans,mul1*hcf);
      }
     long long mul1 =nums[0];
          for(int j=0;j<nums.size();j++){
                long long k = mul1 * nums[j];
                long long m = gcd(mul1, nums[j]);
                mul1 = k / m;
          }
          int hcf=nums[0];
          for(int j=0;j<nums.size();j++){
                  hcf=gcd(hcf,nums[j]);
          }
          ans=max(ans,mul1*hcf);
        return ans;
    }
};