class Solution {
    public long minOperations(int[] nums1, int[] nums2) {

        long ans=0;
        long last=Long.MAX_VALUE;
        int n=nums1.length;
        int val=nums2[n];
        for(int i=0;i<n;i++){
            int no=Math.abs(nums1[i]-nums2[i]);
            ans+=no;
            int a=nums1[i],b=nums2[i];

            if(a>b){
                int tmp=a;
                a=b;
                b=tmp;
            }
            if(a<=val && val<=b){
              last=0;
            }else if(val>b){
                  last=Math.min(last,Math.abs(b-val));
            }else{
                last=Math.min(last,Math.abs(a-val));
            }
        //    System.out.println(a+" "+b+" "+val+" "+last);
        }
       return   ans+=last+1;
    }
}