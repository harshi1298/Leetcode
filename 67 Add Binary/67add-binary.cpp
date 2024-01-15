class Solution {
public:
    string addBinary(string a, string b) {
     int c=a.length()-1;
     int d=b.length()-1;
     int i=c>d?c:d;
     int k=0,m,n;
     int l;
     string str;
     int s=1;
        for(;i>=0||(k);i--){
            s=0;
        if(c>=0){
         m=int(a[c])-48;
         c--;}
        else {
          m=0;}
        if(d>=0){
         n=int(b[d])-48;
         d--;
         }
        else {
          n=0;}
          cout<<m<<" "<<n;
             cout<<l<<" "<<k<<endl;
         l=(m^n^k);
         k=(m^n)*k+m*n;
         str+=(char)(l+48);
     };
         reverse(str.begin(),str.end());
        return str;
         }  
};
