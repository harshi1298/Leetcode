class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        unordered_map<int,int>mapp;
        for(int i=0;i<s.length();i++){
            if(mapp.find(s[i]-'a')==mapp.end()){
                mapp[s[i]-'a']=i;
            }
            else{
                mapp[s[i]-'a']=(i-mapp[s[i]-'a']-1);
            }
        }
        for(int i=0;i<distance.size();i++){
            if(mapp.find(i)!=mapp.end() && mapp[i]!=distance[i]){
                return false;
            }
        }
        return true;
    }
};