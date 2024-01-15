class Solution {
public:
    bool isPalindrome(string s) {
        int l=s.length()-1;
        int k=1,i;
        for( i=0;i<l&&k;){
            k=0;
            if(int(s[i])>64&&int(s[i])<91)
             s[i]=char(int(s[i])+32);
            if(int(s[l])>64&&int(s[l])<91)
             s[l]=char(int(s[l])+32); 
            if((int(s[i])>96&&int(s[i])<123&&int(s[l])>96&&int(s[l])<123)||(int(s[l])<58&&int(s[l])>47&&int(s[i])<58&&int(s[i])>47)){
                if(s[i]==s[l])
                  k=1;
                else
                  break;
                  i++;
                  l--;
               
            }
             else if((int(s[i])<97&&int(s[i])>=58)||int(s[i])>122||int(s[i])<=47){
              i++;
              k=1;}
           else if((int(s[l])<97&&int(s[l])>=58)||int(s[l])>122||int(s[l])<=47){
              l--; 
              k=1;}
           else if(((int(s[i])<97&&int(s[i])>=58)||int(s[i])>122||int(s[i])<=47)&&((int(s[l])<97&&int(s[l])>=58)||int(s[l])>122||int(s[l])<=47)){
                i++;
                l--;
                k=1;
            }                
        }
        cout<<i<<endl;
        cout<<l<<endl;
        if(i>=l&&s[i]==s[l])
         return true;
        else
         return false;
         
    }
};