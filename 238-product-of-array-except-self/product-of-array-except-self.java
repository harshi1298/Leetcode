class Solution {
    public int[] productExceptSelf(int[] nums) {
        long prod=1;
        int cnt=0;
        int n=nums.length;
        for(int i=0;i<n;i++){
            if(nums[i]==0)cnt++;
            else{
                prod*=nums[i];
            }
        }
        int [] ans=new int[n];
        if(cnt>1){ 
            return ans;
        }
        for(int i=0;i<n;i++){
            if(cnt==1){
                if(nums[i]==0)ans[i]=(int)prod;
                else ans[i]=0;
            }
            else{
                ans[i]=(int)(prod/nums[i]);
            }
        }
        return ans;
    }
}