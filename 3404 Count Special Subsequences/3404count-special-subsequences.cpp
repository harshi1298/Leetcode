class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        unordered_map<double,int>mapp;
        for(int i=2;i<n-4;i++){
            for(int j=i-2;j>=0;j--){
                mapp[(double)(nums[i])/(double)(nums[j])]++;
            }
             for(int k=i+4;k<n;k++){
                double r=double(nums[i+2])/double(nums[k]);
                if(mapp.find(r)!=mapp.end()){
                    ans+=(mapp[r]);
                }
             }
        }
        return ans;
    }
};