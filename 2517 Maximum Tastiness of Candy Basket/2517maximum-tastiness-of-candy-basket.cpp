class Solution {
private:
    bool solve(vector<int>&arr,int mid,int l){
        if(mid==0)return 1;
        auto it=arr.begin();
        int count=1;
        int k=arr[0];
        while(it!=arr.end()){
            it=lower_bound(arr.begin(),arr.end(),k+mid);
            if(it!=arr.end()){
                count++;
                k=*it;
            }
            if(count>=l)return true;
        }
        return count>=l;
    }
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int n=price.size(),ans=0;;
        int end=price[n-1]-price[0],st=0;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(solve(price,mid,k)){
              ans=mid;
              st=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
};