class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mapp;
        int l=0,r=0,n=fruits.size();
        int ans=0;
        while(r<n){
            mapp[fruits[r]]++;
            while(mapp.size()>2){
                mapp[fruits[l]]--;
                if(mapp[fruits[l]]==0)mapp.erase(fruits[l]);
                l++;
            }
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};