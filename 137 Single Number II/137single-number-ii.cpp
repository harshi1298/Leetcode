class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a,k=nums.size();
        if(k==1)
        return nums[0];
        else{
        sort(nums.begin(),nums.end());
        for(int i=1;i<k;){
            if(nums[i]==nums[i-1]){
            if(i<k-3)
             i=i+3;
             else{
                a=nums[k-1];
              break;}}
              else{
                  cout<<i<<endl;
                  a=nums[i-1];
                  break;
              }
        }
        return a;}
    }
};