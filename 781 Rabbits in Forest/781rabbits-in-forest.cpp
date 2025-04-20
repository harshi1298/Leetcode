class Solution {
public:
    int numRabbits(vector<int>& answ) {
       unordered_map<int,int>mapp;
       for(auto it :answ){
        mapp[it]++;
       }
       int ans=0;
       for(auto [key,val]:mapp){
          ans+=((val+key)/(key+1)*(key+1));
       }
       return ans;
    }
};