class Solution {
private:
  int isprime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return i;
        }
    }
    return -1;
  }
public:
    int minOperations(vector<int>& nums) {
        int ans=0;
        if(nums.size()==1 || nums.size()==0)return 0;
        for(int i=nums.size()-2;i>=0;i--){
            int flag=0;
            int k=isprime(nums[i]);
            if(k!=-1 && nums[i]>nums[i+1]){
                nums[i]=k;
               flag=1;
            }
            if(flag)ans++;
        }
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1])return -1;
        }
        return ans;
    }
};