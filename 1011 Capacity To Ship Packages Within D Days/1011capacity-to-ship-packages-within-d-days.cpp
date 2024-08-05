class Solution {
private:
   bool ispossible(vector<int> nums,int day,int mid){
    for(int i=0;i<nums.size();i++){
        if(nums[i]>mid) return false;
        int flag=0;
        int sum=0;
        while(i<nums.size() &&sum+nums[i]<=mid){
            sum+=nums[i];
            i++;
            flag=1;
        }
        day--;
        if(flag)i--;
        if(day<0) return false;
    }
    cout<<mid<<" "<<day<<endl;
    if(day>=0) return true;
    else return false;
   }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        for(int i=0;i<weights.size();i++){
            sum+=weights[i];
        }
        int ans=0;
        int i=1;
        int j=sum;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(!ispossible(weights,days,mid)){
                i=mid+1;
            }
            else{
                ans=mid;
                j=mid-1;
            }
        }
        return ans;
    }
};