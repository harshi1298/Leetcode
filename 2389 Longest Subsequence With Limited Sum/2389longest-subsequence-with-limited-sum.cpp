class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<int>arr;
        int sum=0;
        for(auto it : nums){
            sum+=it;
            arr.push_back(sum);
        }
        vector<int>ans;
        for(auto it : queries){
            auto itr=upper_bound(arr.begin(),arr.end(),it);
            if(itr==arr.end())ans.push_back(arr.size());
            else {
                ans.push_back((itr-arr.begin()));
            }
        }
        return ans;
    }
};