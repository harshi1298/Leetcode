class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int,pair<int,int>>mapp;
        int ans=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(mapp.find(nums[i])==mapp.end()){
                mapp[nums[i]]={-1,i};
            }
            else{
                auto [x,y]=mapp[nums[i]];
                if(x!=-1){
                    ans=min(ans,abs(x-y)+abs(y-i)+abs(x-i));
                }
                mapp[nums[i]]={y,i};
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};