class Solution {
public:
    int bestClosingTime(string cus) {
        int n=cus.size();
        vector<int>suff(n+1,0);
        for(int i=n-1;i>=0;i--){
            suff[i]=suff[i+1]+(cus[i]=='Y');
            cout<<suff[i]<<" ";
        }
        int pre=0;
        int mini=n,ans=-1;
        for(int i=0;i<n;i++){
            if(mini>pre+suff[i]){
                mini=pre+suff[i];
                ans=i;
            }
            pre+=(cus[i]=='N');
        }
        if(pre<mini)ans=n;
        return ans;
    }
};