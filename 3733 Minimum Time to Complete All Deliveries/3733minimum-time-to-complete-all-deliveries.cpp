class Solution {
private:
    bool solve(long long mid,vector<int>&d,vector<int>&r){
       long long k1=mid/((r[0]*r[1])/gcd(r[0],r[1]));
       long long av1=mid/r[0];
       long long av2=mid/r[1];
       long long av3=mid-(av1+av2-k1);
       av1=mid-av1;
       av2=mid-av2;
       if((av1>=1ll*d[0] && av2>=1ll*d[1] && av1+av2-av3>=1ll*d[0]+1ll*d[1]))return true;
       return false;
    }
public:
    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long st=0;
        long long end=1e18;
        long long ans=0;
        while(st<=end){
            long long mid=st+(end-st)/2;
            if(solve(mid,d,r)){
              ans=mid;
              end=mid-1;
            }
            else st=mid+1;
        }
        return ans;
    }
};