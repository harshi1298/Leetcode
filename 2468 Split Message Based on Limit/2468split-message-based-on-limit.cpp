class Solution {
private: 
    int isvalid(int mid,int msg){
        long long ans=0;
        int d=to_string(mid).size();
        for(int i=1;i<d;i++){
            ans+=(9ll*(long long )pow(10,i-1)*i);
        }
        ans+=(mid-(long long)(pow(10,d-1))+1)*d;
        ans+=((long long)(d)*1ll*mid);
        ans+=(msg+(3*mid));
        return ans;
    }

public:
    vector<string> splitMessage(string msg, int limit) {
        int n=msg.length();
        int st=1,end=n;
        cout<<end<<endl;
        int last=-1;
          while(st<=end){
            if(isvalid(st,n)<=st*limit){
                last=st;
                break;
            }
            st++;
        }
        vector<string>ans;
        string m =to_string(last);
        int d=m.length();
        int k=0;
        for(int i=1;i<=last;i++){
           string l=to_string(i);
           int l1=l.length();
           int rem=limit-(l1+d+3);
           string temp="";
           for(int j=0;j<rem && k<n;j++){
            temp.push_back(msg[k]);
            k++;
           }
           temp.push_back('<');
           temp+=l;
           temp.push_back('/');
           temp+=m;
           temp.push_back('>');
           ans.push_back(temp);
        }
        return ans;
    }
};