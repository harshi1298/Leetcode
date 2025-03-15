class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& c, int k) {
        for (int i = 0; i < k ; i++) {
            c.push_back(c[i]);
        }
        int l=0,ans=0;
        for(int r=1;r<c.size();r++){
            if(r-l>=k){
                ans++;
            }
            // cout<<ans<<" "<<r<<endl;
            if(c[r]==c[r-1]){
                l=r;
            }
        }
        return ans;
    }
};