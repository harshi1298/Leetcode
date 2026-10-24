class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        PriorityQueue<int []>pq=new PriorityQueue<>((a,b)->{
            if(a[0]==b[0])return Integer.compare(a[1],b[1]);
            return Integer.compare(b[0],a[0]);
        });
        int n=nums.length;
        int [] ans= new int[n-k+1];
        for(int i=0;i<n;i++){
            pq.offer(new int[]{nums[i],i});
            while(!pq.isEmpty() && i-pq.peek()[1]>=k)pq.poll();
            if(i>=k-1){
                ans[i-k+1]=(pq.peek()[0]);
            }
        }
        return ans;
    }
}