class Solution {
public:
    bool check(vector<int>& nums) {
        int l=2;
        int k=nums.size();
        int i=0;
        while(l==2&&k>1){
            if(nums[i]<=nums[i+1]){
            k--; 
            i++; 
            continue;}
            else{
                k--;
                l--;
                i++;
                break;
            }
        }if(k==1&&nums[i]>nums[0])
          l--;
        while(l==1&&k>1){
            if(nums[i]<=nums[i+1]&&nums[0]>=nums[i+1]){
            k--;  
            i++;
            continue;}
            else{
                k--;
                l--;
                i++;
                break;
        }
        }
        return l;
    }
};