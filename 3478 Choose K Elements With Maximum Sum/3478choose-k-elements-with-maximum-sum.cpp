class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int>temp;
        int n=nums1.size();
        for(int i=0;i<n;i++)temp.push_back(i);
        sort(temp.begin(),temp.end(),[&](auto a,auto b){
            return nums1[a]<nums1[b];
        });
        vector<long long>ans(n);
        for(auto it :temp)cout<<it<<" ";
        priority_queue<int,vector<int>,greater<int>>pq;
        long long count=0;
        for(int i=0;i<n;i++){
           if(i>0 &&nums1[temp[i]]<=nums1[temp[i-1]]){
            ans[temp[i]]=ans[temp[i-1]];
            }
          else
           ans[temp[i]]=count;
           if(pq.size()<k){
            pq.push(nums2[temp[i]]);
            count+=nums2[temp[i]];
           }
           else{
            pq.push(nums2[temp[i]]);
            count+=nums2[temp[i]];
            count-=pq.top();
            pq.pop();
           }
        } 
        return ans;
    }
};