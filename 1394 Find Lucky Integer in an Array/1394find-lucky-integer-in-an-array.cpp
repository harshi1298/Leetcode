class Solution {
public:
    int findLucky(vector<int>& arr) {
       unordered_map<int,int>mapp;
       for(auto it :arr){
        mapp[it]++;
       } 
       int ans=-1;
       for(auto [a,b]: mapp){
        if(a==b)ans=max(ans,a);
       }
       return ans;
    }
};