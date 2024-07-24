class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> ans1;
        for(int i=0;i<nums.size();i++){
            int temp=nums[i],p=0,k=1;
            if(temp==0){
                p=mapping[0];
            }
            else{
            while(temp!=0){
                p=(mapping[temp%10])*k+p;
                k*=10;
                temp/=10;
            }}
            ans1.push_back({p,nums[i]});
        }       
        sort(ans1.begin(),ans1.end(),[&](auto a,auto b){
            return a.first<b.first;
        });
        vector<int> ans;
        for(auto i:ans1){
            ans.push_back(i.second);
        }
        return ans;
    }
};