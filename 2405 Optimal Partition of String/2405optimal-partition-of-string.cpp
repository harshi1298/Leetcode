class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int>mapp;
        int ans=1;
        for(int i=0;i<s.length();i++){
            if(mapp.find(s[i])!=mapp.end()){
                ans++;
                mapp.clear();
            }
            mapp[s[i]]=1;
        }
        return ans;
    }
};