class Solution {
private:
     long long countsub(string s){
        long long n=s.length(), total=1l*n*(n+1)/2;
        long long len=0,temp=0;
        for(int i=0;i<n;i++){
            if(s[i]!='*'){
                len++;
            }
            else{
                temp+=(len*(len+1)/2);
                len=0;
            }
        }
        if(len>0)temp+=(len*(len+1)/2);
        return total-temp;
     }
public:
    int minTime(string s, vector<int>& order, int k) {
        int n=s.length();
        int ans=-1;
        int st=0,end=n-1;
        while(st<=end){
            int mid=(st+(end-st)/2);
            int count=0;
            string temp=s;
            for(int i=0;i<=mid;i++){
                temp[order[i]]='*';
            }
            if(countsub(temp)>=k){
                ans=mid;
                end=mid-1;
            }
            else st=mid+1;
        }
        return ans;
    }
};