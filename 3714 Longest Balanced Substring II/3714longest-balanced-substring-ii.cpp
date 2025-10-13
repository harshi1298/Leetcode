class Solution {
private:
    int solve(string s,char x,char y){
        int ans=0,count=0,n=s.length();
        unordered_map<int,int>mapp;
        mapp[0]=-1;
        for(int i=0;i<n;i++){
            if(s[i]==x){
                count++;
            }
            else if(s[i]==y)count--;
            else{
                count=0;
                mapp.clear();
            }
            if(mapp.find(count)!=mapp.end()){
                ans=max(ans,i-mapp[count]);
            }
            else mapp[count]=i;
        }
        return ans;
    }
public:
    int longestBalanced(string s) {
        int ans=1,n=s.length();
        int count=1;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                count++;
            }
            else{
                ans=max(ans,count);
                count=1;
            }
            ans=max(ans,count);
        }
        ans=max(ans,solve(s,'a','b'));
        ans=max(ans,solve(s,'a','c'));
        ans=max(ans,solve(s,'c','b'));
        int acnt=0,bcnt=0,ccnt=0;
        map<pair<int,int>,int>mapp;
        mapp[{0,0}]=-1;
        for(int i=0;i<n;i++){
            acnt+=s[i]=='a';
            bcnt+=s[i]=='b';
            ccnt+=s[i]=='c';
            if(mapp.find({acnt-bcnt,acnt-ccnt})!=mapp.end()){
                ans=max(ans,i-mapp[{acnt-bcnt,acnt-ccnt}]);
            }
            else{
                mapp[{acnt-bcnt,acnt-ccnt}]=i;
            }
        }
        return ans;
    }
};