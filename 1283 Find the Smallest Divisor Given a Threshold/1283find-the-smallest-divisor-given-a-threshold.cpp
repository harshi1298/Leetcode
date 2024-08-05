class Solution {
private:
    bool ispossible(vector<int>nums,int key,int mid){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%mid!=0){
                sum=sum+1+(nums[i]/mid);
            }
            else sum=sum+(nums[i]/mid);
        }
        if(sum<=key) return true;
        else return false;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int i=1;
        int ans=INT_MAX;
        int j=*max_element(nums.begin(),nums.end());
        while(i<=j){
            int mid=i+(j-i)/2;
            if(!ispossible(nums,threshold,mid)){
                i=mid+1;
            }
            else{
                ans=mid;
                j=mid-1;
            }
        }
        return ans;
    }
};