class Solution {
private:
    bool isvalid(vector<int>nums,int mid,long long k){
        for(int i=0;i<nums.size();i++){
           k=k-(nums[i]/mid);
           if(k<=0)return true;
        }
        return false;
    }
public:
    int maximumCandies(vector<int>& c, long long k) {
        int mini=1,ans=0,maxi=*max_element(c.begin(),c.end());
        while(mini<=maxi){
            int mid=mini+(maxi-mini)/2;
           
            if(isvalid(c,mid,k)){
                ans=mid;
                mini=mid+1;
            }
            else maxi=mid-1;
        }
        return ans;
    }
};