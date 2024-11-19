class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum=0,ans=0;
        unordered_map<int,int>mapp;
        int i=0,j=0;
        while(j<nums.size()){
            if(k>0){
                if(!mapp[nums[j]]){
                    sum+=nums[j];
                    k--;
                    if(k==0)
                    ans=max(ans,sum);
                    mapp[nums[j]]=1;
                    j++;
                }
                else{
                    while(i<j && nums[i]!=nums[j]){
                        k++;
                        sum=sum-nums[i];
                        mapp[nums[i]]=0;
                        i++;
                    }
                    k++;
                    sum=sum-nums[i];
                    mapp[nums[i]]=0;
                    i++;
                }
            }
            else{
                sum=sum-nums[i];
                mapp[nums[i]]=0;
                k++;
                i++;
            }
        }
        return ans;
    }
};