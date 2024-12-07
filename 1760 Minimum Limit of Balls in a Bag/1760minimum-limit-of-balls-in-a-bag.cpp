class Solution {
private:
bool ispossible(int mid, vector<int>& nums, int m){
    int op = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > mid) {
            op += (nums[i] - 1) / mid; 
        }
        if (op > m) return false; 
    }
    return true;
}
public:
    int minimumSize(vector<int>& nums, int m) {
        int maxi=*max_element(nums.begin(),nums.end());
        int i=1;
        int ans=maxi;
        while(i<=maxi){
          int mid=i+(maxi-i)/2;
          if(ispossible(mid,nums,m)){
            ans=mid;
            maxi=mid-1;
          }else{
            i=mid+1;
          }
        }
        return ans;
    }
};