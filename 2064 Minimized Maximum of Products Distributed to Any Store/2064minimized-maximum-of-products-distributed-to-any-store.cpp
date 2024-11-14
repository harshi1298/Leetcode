class Solution {
private:
   int ispossible(int mid, vector<int>q,int l ){
       int i=0;
       int ans=mid;
       while(i<q.size() && l){
        while(q[i]>0 && l){
            q[i]=q[i]-mid;
            ans=max(ans,mid);
            l--;
        }
        i++;
       }
       if(i==q.size() && q[q.size()-1]<=0)return ans;
       return INT_MAX;
   }
public:
    int minimizedMaximum(int n, vector<int>& q) {
       int j=*max_element(q.begin(),q.end());
       int ans=j,i=0;
       while(i<=j){
        int mid=i+((j-i)/2);
        int k=ispossible(mid,q,n);
        if(k<=ans){
          ans=k;
          j=mid-1;
        }else{
          i=mid+1;
        }
       }
       return ans; 
    }
};