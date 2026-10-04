class Solution {
    public int subarraySum(int[] nums, int k) {
        HashMap<Integer,Integer>mapp=new HashMap<>();
        int n=nums.length;
        int sum=0,ans=0;
        mapp.put(0,1);
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(mapp.containsKey(sum-k)){
                ans+=mapp.get(sum-k);
            }
            mapp.put(sum,mapp.getOrDefault(sum,0)+1);
        }
        return ans;
    }
}