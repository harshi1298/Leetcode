class Solution {
    public int subarraysWithKDistinct(int[] nums, int k) {
       
        return solve(k,nums)-solve(k-1,nums);
    }

    public int solve(int k,int[] nums){
         int res=0;

        Map<Integer,Integer>map=new HashMap<>();
        int left=0;
        for(int i=0;i<nums.length;i++){
            map.put(nums[i],map.getOrDefault(nums[i],0)+1);
            while(map.size()>k){
               
                 map.put(nums[left],map.getOrDefault(nums[left],0)-1);
                 if(map.get(nums[left])==0)map.remove(nums[left]);
                 left++;
            }
             res+=i-left+1;
        }
        return res;
    }
}