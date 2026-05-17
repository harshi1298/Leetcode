class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if(k==1)return r-l+1;
        int ans=0;
        for(long long i=0;i*i<=r;i++){
            long long temp=1;
            long long tk=k;
            while(tk>0){
                temp*=i;
                tk--;
                if(temp>r)break;
            }
            if(temp>=l && temp<=r && tk==0)ans++;
            // cout<<i<<" "<<temp<<" "<<tk<<endl;
        }
        return ans;
    }
};