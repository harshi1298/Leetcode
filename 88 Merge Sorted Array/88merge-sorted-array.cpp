class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<n;i++){
        int temp=nums2[i];
        nums1[m]=nums2[i];
           for(int j=m;j>0;j--){
               if(nums1[j]<nums1[j-1]){
                   nums1[j]=nums1[j-1];
                   nums1[j-1]=temp;
               }
               else
                break;
           }
           m++;
        }
    return ;
    }
};