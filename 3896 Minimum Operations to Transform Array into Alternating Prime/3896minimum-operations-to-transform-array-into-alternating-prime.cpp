class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int>isprime(2e5+1,1);
        vector<int>st;
        vector<int>st2;
        isprime[0]=0;
        isprime[1]=0;
        st2.push_back(0);
        st2.push_back(1);
        for(long long i=2;i<=2e5;i++){
            if(isprime[i]){
                st.push_back(i);
                for(long long j=i*i;j<=2e5;j+=i){
                    isprime[j]=0;
                }
            }
        }
        for(int i=2;i<=2e5;i++){
            if(!isprime[i])st2.push_back(i);
        }
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(i%2){
                auto it=lower_bound(st2.begin(),st2.end(),nums[i]);
                ans+=(*it-nums[i]);
                // nums[i]=*it;
            }
            else{
                auto it=lower_bound(st.begin(),st.end(),nums[i]);
                ans+=(*it-nums[i]);
                // nums[i]=*it;
            }
        }
        // for(auto it : nums)cout<<it<<" ";
        return ans;
    }
};