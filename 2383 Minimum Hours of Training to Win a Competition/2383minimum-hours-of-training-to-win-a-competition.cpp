class Solution {
public:
    int minNumberOfHours(int e, int iexp, vector<int>& energy, vector<int>& exp) {
        int n=energy.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(iexp<=exp[i]){
                ans+=(exp[i]-iexp+1);
                iexp=exp[i]+1;
                e+=(exp[i]-iexp+1);
            }
            if(e<=energy[i]){
                ans+=(energy[i]-e+1);
                e=energy[i]+1;
                iexp+=(energy[i]-e+1);
            }
            e-=energy[i];
            iexp+=exp[i];
        }
        return ans;
    }
};