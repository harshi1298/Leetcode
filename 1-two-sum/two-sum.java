class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n=nums.length;
        int [][] arr= new int[n][2];
        for(int i=0;i<n;i++){
            arr[i][0]=nums[i];
            arr[i][1]=i;
        }
        Arrays.sort(arr,(a,b) -> Integer.compare(a[0],b[0]));
        for(int i=0,j=n-1;i<j;){
           if(arr[i][0]+arr[j][0]==target)return new int[]{arr[i][1],arr[j][1]};
           else if(arr[i][0]+arr[j][0]<target)i++;
           else j--;
        }
        return new int[]{};
    }
}