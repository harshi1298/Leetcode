class Solution {
public:
    int maxSubstrings(string word) {
        unordered_map<char,int>mapp;
        int ans=0;
        int n=word.size();
        for(int i=0;i<n;i++){
            if(mapp.find(word[i])==mapp.end()){
                mapp[word[i]]=i;
            }
            else{
                if(i-mapp[word[i]]>=3){
                    ans++;
                    mapp.clear();
                }
            }
        }
        return ans;
    }
};