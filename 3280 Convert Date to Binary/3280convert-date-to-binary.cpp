class Solution {
private:
    string convertbinary(int a){
        string b="";
        while(a!=0){
            int k=a&1;
            a=a>>1;
            b=char(k+'0')+b;
        }
        return b;
    }
public:
    string convertDateToBinary(string date) {
        int year=0;
        int month=0;
        int day=0;
        string ans="";
        for(int i=0;i<4;i++){
           year=year*10+(date[i]-'0');
        }
        month=month+(date[5]-'0');
        month=month*10+(date[6]-'0');
        day=day+(date[8]-'0');
        day=day*10+(date[9]-'0');
        ans=convertbinary(year)+"-"+convertbinary(month)+"-"+convertbinary(day);
        return ans;
    }
};