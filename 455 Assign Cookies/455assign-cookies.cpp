class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
       sort(g.begin(),g.end());
       sort(s.begin(),s.end());
       int num_cookie=s.size();
       int greed_s=g.size();
       int ans=0;
       for(int i=0,j=0;i<greed_s && j<num_cookie;){
        if(s[j]>=g[i]){
            i++;
            j++;
            ans++;
        }
        else j++;
       }
       return ans;
    }
};