class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count=0;
        vector<int>temp1(26,-1);
        vector<int>temp2(26,-1);
        int ans=0;
        for(int i=0;i<word.length();i++){
            char it=word[i];
            if(islower(it))temp1[it-'a']=i;
            else if(temp2[it-'A']==-1) temp2[it-'A']=i;
        }
        for(int i=0;i<26;i++){
            if(temp1[i]>-1 && temp2[i]>-1 && temp1[i]<temp2[i])ans++; 
        }
        return ans;
    }
};