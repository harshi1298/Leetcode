class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int>f(26,0);
        for(auto it:s){
            int val=it-'a';
            f[val]++;
        }
        string k="";
        for(auto it:target){
            int val=it-'a';
            if(f[val]>0){
                k+=it;
                f[val]--;
            }else if(f[val]==0){
                for(int i=val+1;i<26;i++){
                    if(f[i]>0){
                        k+=('a'+i);
                        f[i]--;
                        for(int j=0;j<26;j++){
                            int v=f[j];
                            while(v--){
                                k+=('a'+j);
                            }
                        }
                        return k;
                    }
                }
                int l=k.size();
                while(l--){
                    char ch=k.back();
                    int v=ch-'a';
                    k.pop_back();
                    f[v]++;
                    for(int i=v+1;i<26;i++){
                        if(f[i]>0){
                            k+=('a'+i);
                            f[i]--;
                            for(int j=0;j<26;j++){
                                int va=f[j];
                                while(va--){
                                    k+=('a'+j);
                                }
                            }
                            return k;
                        }
                    }
                }
                return k;
            }
        }
        if(k==target){
            next_permutation(k.begin(),k.end());
            if(k>target)return k;
        }
        return "";
    }
}; 