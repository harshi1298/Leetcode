class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int size=words.size();
        unordered_map<char,bool>mapp;
        int ans=0;
        for(int i=0;i<allowed.length();i++)mapp[allowed[i]]=true;
        for(int i=0;i<size;i++){
            bool present=true;
            for(int j=0;j<words[i].length();j++){
               if(!mapp[words[i][j]]){
                 present=false;
                 break;
               }
            }
            if(present)ans++;
        }
        return ans;
    }
};