class Solution {
public:
    bool sumGame(string num) {
        int cn1=0,cn2=0,n=num.length();
        int t1=0,t2=0;
        for(int i=0;i<n;i++){
            if(i<n/2){
                t1+=num[i]=='?'?0:num[i]-'0';
                cn1+=num[i]=='?';
            }
            else{
                t2+=num[i]=='?'?0:num[i]-'0';
                cn2+=num[i]=='?';
            }
        }
        if(cn1==cn2)return t1!=t2;
        if((cn1+cn2)%2)return 1;
        return (cn1-cn2)/2*9!=(t2-t1);
       
    }
};