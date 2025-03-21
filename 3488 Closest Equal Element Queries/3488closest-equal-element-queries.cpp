class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
       unordered_map<int,vector<int>>mapp;
       int n=nums.size();
       for(int i=0;i<n;i++){
          mapp[nums[i]].push_back(i);
       }
       vector<int>tmp(n);
       for(auto &t :mapp){
        auto it=t.second;
        if(it.size()==1){
            tmp[it[0]]=-1;
        }
        else{
            for(int i=0;i<it.size();i++){
                int temp1,temp2;
                if(i+1>=it.size()){
                    temp1=n-it[i]+it[(i+1)%it.size()];
                }
                else temp1=it[i+1]-it[i];
                if(i==0){
                   temp2=n-it[it.size()-1]+it[0];
                }
                else temp2=it[i]-it[i-1];
                tmp[it[i]]=min(temp1,temp2);
            }
        }
       }
       vector<int>ans;
       for(int i:queries){
        // cout<<i<<" ";
        // cout<<tmp[i]<<" ";
          ans.push_back(tmp[i]);
       }
       return ans;
    }
};