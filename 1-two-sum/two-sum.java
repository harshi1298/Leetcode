class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n=nums.length;
        HashMap<Integer,Integer>mapp=new HashMap<>();
        for(int i=0;i<n;i++){
           if(mapp.containsKey(target-nums[i])){
            return new int[]{i,mapp.get(target-nums[i])};
           }
           mapp.put(nums[i],i);
        }
        return new int[]{};
    }
}