class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        vector<int>temp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            auto it=upper_bound(temp.begin(),temp.end(),nums[i]);
            if(temp.empty() || it==temp.end()){
                temp.push_back(nums[i]);
            }
            else{
                int idx=it-temp.begin();
                temp[idx]=nums[i];
            }
        }
        cout<<temp.size();
        return temp.size()>=n-1;
    }
};