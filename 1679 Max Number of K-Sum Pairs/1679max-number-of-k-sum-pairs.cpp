class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        multiset<int>mapp;
        int ans=0;
        for(auto it : nums){
            auto x=mapp.find(k-it);
            if(x!=mapp.end()){
                mapp.erase(x);
                ans++;
            }
            else{
                mapp.insert(it);
            }
        }
        return ans;
    }
};