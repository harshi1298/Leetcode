class Solution {
public:
    int maxDistance(string tmp, int k) {
        int n=0,s=0,e=0,w=0,ans=0;
        for(int i=0;i<tmp.length();i++){
            if(tmp[i]=='N')n++;
            if(tmp[i]=='S')s++;
            if(tmp[i]=='E')e++;
            if(tmp[i]=='W')w++;
            int nsmx=max(n,s);
            int nsmn=min(n,s);
            int esmx=max(e,w);
            int esmn=min(e,w);
            int etc=0;
           if(nsmn+esmn>=k){
              etc=nsmn+esmn-2*k;
           }
           else{
            etc=(nsmn+esmn)*-1;
           }
            ans=max(ans,(nsmx+esmx-etc));
        }
        return ans;
    }
};