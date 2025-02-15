class Solution {
private:
    bool solve(string a,int i,int j,int sum,int req){
       if(i>=j){
        return sum==req;
       }
       for(int k=i+1;k<=j;k++){
         string temp1=a.substr(i,k-i);
         if(solve(a,k,j,sum+(stoi(temp1)),req)){
            return true;
         }
       }
       return false;
    }
public:
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            string temp=to_string(i*i);
            if(solve(temp,0,temp.length(),0,i)){
                ans+=(i*i);
            }
        }
        return ans;
    }
};