class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int>arr1,arr2;
        for(auto it : flowers){
            arr1.push_back(it[0]);
            arr2.push_back(it[1]);
        }
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        vector<int>ans;
        for(auto it : people){
            auto c1=upper_bound(arr1.begin(),arr1.end(),it)-arr1.begin();
            auto c2=lower_bound(arr2.begin(),arr2.end(),it)-arr2.begin();
            ans.push_back(c1-c2);
        }
        return ans;
    }
};