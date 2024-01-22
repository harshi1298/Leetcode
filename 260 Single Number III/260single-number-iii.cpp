class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int k=nums.size();
        vector<int>ans;
        sort(nums.begin(),nums.end());
        for(int i=1;i<k;){
            if(nums[i]!=nums[i-1]){
             ans.push_back(nums[i-1]);
             if(i==k-1)
             ans.push_back(nums[i]);
             i++;}
             else{
             if(i<k-2)
             i=i+2;
             else{
                 if(i==k-1)
                 break;
                 if(nums[i]!=nums[i+1])
                 ans.push_back(nums[k-1]);
             break;}}
        }
        return ans;
    }
};