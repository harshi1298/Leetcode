class Solution {
public:
    bool halvesAreAlike(string s) {
        int k=s.length();
       for(int i=0;i<k;i++)
          s[i]=tolower(s[i]);
        int l=k;
        k=k/2;
        int c=0;
        int d=0;
        int a=0;
        int b=0;
        for(int i=0;i<k;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
              c++;
            else
              d++;
        }
        for(int i=k;i<l;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
              a++;
            else
              b++;
        }
        cout<<a<<b<<c<<d;
        if(a==c&&b==d)
          return 1;
        else
          return 0;
    }
};