class Solution {
public:
    void solve(vector<int> &ans,int digimin,int high,int countmin,int countmax,int low){
        int l=0;
       while(countmin<=countmax&&l<high){
          int sum=digimin;
           int j=0;
           int k=1;
           while(j+1<countmin){ 
               if(sum%10==9){
                   k=0;
                   break;
               }
           sum=sum*10+(digimin+j+1);
           j++;
       }
    if(sum>=low&&k&&sum<=high)
       ans.push_back(sum);
       l=sum;
   if(l%10==9)
       {countmin++;
       digimin=1;}
     else
       digimin++;}
    }
    vector<int> sequentialDigits(int low, int high) {
        if(high==low)
            return {};
        int count=0;
        int count2=0;
        int p=0;
        int x=low;
        while(low){
            p=low;
            low/=10;
            count++;
        }
        int k=0;
        int s=high;
        while(high){
            k=high;
            high/=10;
            count2++;
        }
        vector<int> ans;
        solve(ans,p,s,count,count2,x);
        return ans;
    }
};