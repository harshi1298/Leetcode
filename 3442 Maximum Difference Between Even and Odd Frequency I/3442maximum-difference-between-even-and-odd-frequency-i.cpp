class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>mapp;
        for(int i=0;i<s.length();i++){
            mapp[s[i]]++;
        }
        int mine=101,maxe=0,mino=101,maxo=0;
        for(auto it:mapp){
            if(it.second%2){
                maxo=max(maxo,it.second);
                mino=min(mino,it.second);
            }
            else{
               maxe=max(maxe,it.second);
               mine=min(mine,it.second);
            }
        }
        int ans=(maxo-mine);
        return ans;
    }
};