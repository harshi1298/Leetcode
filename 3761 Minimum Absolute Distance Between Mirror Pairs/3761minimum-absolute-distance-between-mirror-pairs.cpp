class Solution {
int findrev(int n){
    int ans=0;
    while(n>0){
        ans=ans*10+n%10;
        n/=10;
    }
    return ans;
}
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>mapp;
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(mapp.find(nums[i])!=mapp.end()){
                ans=min(ans,i-mapp[nums[i]]);
            }
            mapp[findrev(nums[i])]=i;
        }
        return ans==INT_MAX?-1:ans;
    }
};