class Solution {
private:
  int count=0;
  string ans="";
  string s;
  int total;
  void solve(string temp,int i){
    if(i==s.length()){
    count++;
    if(count==total){
        ans=temp;
      }
    return;
    }
    for(int j=0;j<3;j++){
        if(temp.size()>0 && temp.back()==(char)('a'+j))continue;
        temp.push_back((char)('a'+j));
        solve(temp,i+1);
        temp.pop_back();
    }
  }
public:
    string getHappyString(int n, int k) {
        total=k;
        for(int i=0;i<n;i++){
            s.push_back('c');
        }
        solve("",0);
        return ans;
    }
};