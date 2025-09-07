class Solution {
long long find(int tmp){
  int i=1,b=1;
  long long ans=0;
  while(b<=tmp){
     ans+=1ll*(i+1)/2*(min(tmp,b*2-1)-b+1);
     i++;
     b*=2;
  }
  return ans;
}
public:
    long long minOperations(vector<vector<int>>& queries) {
        long  long ans=0;
        for(auto it:queries){
            long long k=find(it[0]-1);
            long long l=find(it[1]);
            ans+=(l-k+1)/2;
        }
        return ans;
    }
};