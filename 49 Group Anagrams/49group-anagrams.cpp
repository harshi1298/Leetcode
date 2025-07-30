class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mapp;
        int n=strs.size();
        for(int i=0;i<n;i++){
            string t=strs[i];
            sort(strs[i].begin(),strs[i].end());
            mapp[strs[i]].push_back(t);
        }
        vector<vector<string>>ans;
        for(auto [_,val]: mapp){
            ans.push_back(val);
        }
        return ans;
    }
};