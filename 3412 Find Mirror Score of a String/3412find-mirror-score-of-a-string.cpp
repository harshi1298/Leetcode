class Solution {
public:
    long long calculateScore(string s) {
        long long ans=0;
        unordered_map<char,vector<int>>mapp;
        for(int i=0;i<s.length();i++){
            char c=char(26-(s[i]-'a')+'a'-1);
            if(mapp[c].size()!=0){
                int t=mapp[c].back();
                ans+=(i-t);
                mapp[c].pop_back();
            }
            else mapp[s[i]].push_back(i);
        }
        return ans;
    }
};