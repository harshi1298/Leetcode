class Solution {
public:
   void swap(int* a,int* b){
       int temp=*a;
       *a=*b;
       *b=temp;
   }
    int removeElement(vector<int>& nums, int val) {
        int l=nums.size();
        int i;
        int k=0;
        for(int i=0;i<l;i++){
            if(nums[i]!=val){
                nums[k]=nums[i];
                k++;
            }
        }
        return k;
    }
};