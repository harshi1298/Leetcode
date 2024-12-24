class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>mapp;
        int mini=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int temp;
            if(nums[i]-k<=mini){
                temp=mini+1;
            }
            else{
                temp=nums[i]-k;
            }
            while(temp<=nums[i]+k && mapp[temp]){
                temp++;
            }
            if(temp<=nums[i]+k){
            mapp[temp]=1;
            mini=temp;}
        }
        return mapp.size();
    }
};