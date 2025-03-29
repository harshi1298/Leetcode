class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        unordered_map<int,int>mapp;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1')ans++;
        }
        int temp=ans;
        int prev=0;
        for(int i=0;i<s.length();){
            if(s[i]=='0'){
                prev++;
                i++;
                continue;
            }
           while(s[i]=='1'){
               i++;
           }
            int count=0;
            bool flag=0;
            while(s[i]=='0' && prev>0){
                count++;
                i++;
                flag=1;
            }
            if(flag){
                ans=max(ans,temp+prev+count);
                prev=count;
            }
        }
        return ans;
    }
};