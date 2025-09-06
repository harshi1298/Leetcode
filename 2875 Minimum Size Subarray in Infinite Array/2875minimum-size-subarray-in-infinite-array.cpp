class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        vector<long long> prefix{0};
        int n=nums.size();
        for(auto &it:nums) prefix.push_back(prefix.back()+it);
        long long total=prefix.back();
        
        map<long long,int> suffmapp;
        set<long long> st;
        int ans=INT_MAX;
        long long sum=0;
        st.insert(sum);
        suffmapp[sum]=0;
        for(int i=n-1;i>=0;i--){
            sum+=nums[i];
            if(st.find(sum)==st.end()){
                st.insert(sum);
                suffmapp[sum]=n-i;
            }
        }

        
        if(target<=total){
            unordered_map<int,int> mapp;
            long long sum=0;
            mapp[0]=-1;
            for(int i=0;i<n;i++){
                sum+=nums[i];
                if(mapp.find(sum-target)!=mapp.end()) ans=min(ans,i-mapp[sum-target]);
                mapp[sum]=i;

            }
        }

        for(int i=0;i<=n && target>=prefix[i];i++){
            long long t=target-prefix[i];
            int op=t/total * n;
            t-=(t/total *total);
            if(st.find(t)!=st.end()){
                ans=min(ans,op+i+suffmapp[t]);
            }
            cout<<t<<" ";
        }
        return ans==INT_MAX?-1:ans;
    }
};