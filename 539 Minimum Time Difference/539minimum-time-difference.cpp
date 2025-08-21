int solve(string a,string b){
    int h1=((a[0]-'0')*10+(a[1]-'0'))*60+((a[3]-'0')*10+a[4]-'0');
    int h2=((b[0]-'0')*10+(b[1]-'0'))*60+((b[3]-'0')*10+b[4]-'0');
    return h2-h1;
}
class Solution {
public:
    int findMinDifference(vector<string>& t) {
        sort(t.begin(),t.end());
        int n=t.size();
        string temp=t[0];
        temp[0]+=2;
        temp[1]+=4;
        int ans=solve(t[n-1],temp);
        for(int i=1;i<n;i++){
            ans=min(ans,solve(t[i-1],t[i]));
        }
        return ans;
    }
};