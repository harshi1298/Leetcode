class Solution {
private:
    bool ispossible(vector<int>& day, int m, int k,int mid){
        int count=0;
        for(int i=0;i<day.size() && m ;i++){
            if(day[i]<=mid)count++;
            else{
                count=0;
            }
            if(count==k){
                m--;
                count=0;
            }
        }
        if(m==0)return true;
        return false;
    }
public:
    int minDays(vector<int>& day, int m, int k) {
        int j=*max_element(day.begin(),day.end()),i=0,ans=-1;
        while(i<=j){
            int mid=(j-i)/2+i;
            if(ispossible(day,m,k,mid)){
               ans=mid;
               j=mid-1;
            }
            else i=mid+1;
        }
        return ans;
    }
};