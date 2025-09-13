class Solution {
public:
    int minArrivalsToDiscard(vector<int>& nums, int w, int m) {
        int l=0;
        int n=nums.size();
        unordered_map<int,int>mapp;
        int ans=0;
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            mapp[nums[i]]++;
            while(l<max(0,(i-w+1))){
                if(st.find(l)==st.end())
                  mapp[nums[l]]--;
                l++;
            }
            if(mapp[nums[i]]>m){
                st.insert(i);
                mapp[nums[i]]--;
                ans++;
            }
        }
        return ans;
    }
};