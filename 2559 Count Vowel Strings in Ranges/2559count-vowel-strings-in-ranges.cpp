class Solution {
private:
    bool isvowel(char a){
        return a=='a' || a=='e' || a=='i' || a=='o' || a=='u';
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int count=0,n=words.size();
        vector<int>pre(n,0);
        for(int i=0;i<n;i++){
            int l=words[i].length();
            if(isvowel(words[i][0]) && isvowel(words[i][l-1]))count++;
            pre[i]=count;
        }
        vector<int>ans;
        for(auto it : queries){
            int st=it[0],e=it[1];
            int left=st==0?0:pre[st-1];
            int end=pre[e];
            ans.push_back(end-left);
        }
        return ans;
    }
};