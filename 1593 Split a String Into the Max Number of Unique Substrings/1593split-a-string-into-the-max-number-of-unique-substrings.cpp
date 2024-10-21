class Solution {
private:
   unordered_map<string,int>mapp;
   int ans=0;
   int count=0;
   void solve(string s,int index){
    if(index>=s.length()){
        ans=max(ans,count);
        return;}
    count++;
    for(int i=index;i<s.length();i++){
        if(!mapp[s.substr(index,i-index+1)]){
            mapp[s.substr(index,i-index+1)]=1;
            solve(s,i+1);
            mapp[s.substr(index,i-index+1)]=0;
        }
    }
     count--; 
   }
public:
    int maxUniqueSplit(string s) {
        solve(s,0);
        return ans;
    }
};