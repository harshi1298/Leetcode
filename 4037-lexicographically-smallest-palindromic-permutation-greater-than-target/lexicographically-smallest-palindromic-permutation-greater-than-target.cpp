class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n=s.size();
        vector<int>f(26,0);
        for(auto it:s){
            int v=it-'a';
            f[v]++;
        }
        int c=0;
        char ch='_';
        for(int i=0;i<26;i++){
            int it=f[i];
            if(it%2==1){
                c++;
                ch='a'+i;
            }
        }
        if(c!=n%2)return "";
        vector<int>hf(26,0);
        for(int i=0;i<26;i++){
            hf[i]=f[i]/2;
        }
        string k="";
        n/=2;
        for(int x=0;x<n;x++){
            auto it=target[x];
            int val=it-'a';
            if(hf[val]>0){
                k+=it;
                hf[val]--;
            }else if(hf[val]==0){
                for(int i=val+1;i<26;i++){
                    if(hf[i]>0){
                        k+=('a'+i);
                        hf[i]--;
                        for(int j=0;j<26;j++){
                            int v=hf[j];
                            while(v--){
                                k+=('a'+j);
                            }
                        }
                        string res=k;
                        if(ch!='_')res+=ch;
                        reverse(k.begin(),k.end());
                        res+=k;
                        return res;
                    }
                }
                int l=k.size();
                while(l--){
                    char c=k.back();
                    int v=c-'a';
                    k.pop_back();
                    hf[v]++;
                    for(int i=v+1;i<26;i++){
                        if(hf[i]>0){
                            k+=('a'+i);
                            hf[i]--;
                            for(int j=0;j<26;j++){
                                int va=hf[j];
                                while(va--){
                                    k+=('a'+j);
                                }
                            }
                            string res=k;
                            if(ch!='_')res+=ch;
                            reverse(k.begin(),k.end());
                            res+=k;
                            return res;
                        }
                    }
                }
                return k;
            }
        }
        string res=k;
        if(ch!='_')res+=ch;
        reverse(k.begin(),k.end());
        res+=k;
        reverse(k.begin(),k.end());
        string sub=target.substr(0,n);
        if(res>target)return res;
        if(res<=target){
            next_permutation(k.begin(),k.end());
            if(k>sub){
                res=k;
                if(ch!='_')res+=ch;
                reverse(k.begin(),k.end());
                res+=k;
                return res;
            }
        }
        return "";
    }
};