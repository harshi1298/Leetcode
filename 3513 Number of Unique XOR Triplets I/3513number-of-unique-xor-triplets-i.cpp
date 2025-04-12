class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        int count=0;
        if(nums.size()<3)return nums.size();
        while(maxi){
            count++;
            maxi=maxi>>1;
        }
        int ans=pow(2,count);
        return ans;
    }
};