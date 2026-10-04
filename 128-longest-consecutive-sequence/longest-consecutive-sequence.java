class Solution {
    public int longestConsecutive(int[] nums) {
        int n=nums.length;
        HashSet<Integer>st=new HashSet<>();
        for(int i=0;i<n;i++){
            st.add(nums[i]);
        }
        int ans=0;
        for(int i=0;i<n && !st.isEmpty() ;i++){
           int count=0;
           int j=0,k=nums[i];
           while(st.contains(k+j)){
            st.remove(k+j);
            count++;
            j++;
           }
           j=1;
           while(st.contains(k-j)){
            st.remove(k-j);
            count++;
            j++;
           }
           ans=Math.max(ans,count);
        }
        return ans;
    }
}