class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int>ans;
        int n=spells.size(),m=potions.size();
        for(int i=0;i<n;i++){
            long long l=success%spells[i]?success/spells[i]+1:success/spells[i];
            auto it=lower_bound(potions.begin(),potions.end(),l);
            if(it==potions.end())ans.push_back(0);
            else{
                ans.push_back(potions.end()-it);
            }
        }
        return ans;
    }
};