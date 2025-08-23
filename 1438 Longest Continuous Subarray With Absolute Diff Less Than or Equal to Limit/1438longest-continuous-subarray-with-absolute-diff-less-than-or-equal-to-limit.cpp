class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        // int minindex=-1,maxindex=-1,invalid=-1;
        int n=nums.size();
        // int ans=0;
        priority_queue<pair<int,int>>maxpq;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>minpq;
        // for(int i=0;i<n;i++){
            // if(maxindex==-1 && minindex==-1){
            //     maxindex=i;minindex=i;
            // }
            // if(nums[maxindex]<nums[i]){
            //     maxindex=i;
            // }
            // if(nums[minindex]>nums[i]){
            //    minindex=i;
            // }
            // if(abs(nums[minindex]-nums[maxindex])>limit){
            //     invalid=i;
            //     if(minindex<maxindex){
            //         while(abs(nums[minindex]-nums[maxindex])>limit){
            //             minindex++;
            //         }
            //     }
            //     else{
            //        while(abs(nums[minindex]-nums[maxindex])>limit){
            //             maxindex++;
            //         } 
            //     }
            // }
            // ans=max(ans,i-min(maxindex,minindex)+1);
            //  cout<<i<<" "<<maxindex<<" "<<minindex<<" "<<ans<<endl;

            
        // }
        int i=0;
        int j=0;
        int ans = 0;
        while(j<n){
            maxpq.push({nums[j],j});
            minpq.push({nums[j],j});

            while(!maxpq.empty() and !minpq.empty() and abs(maxpq.top().first - minpq.top().first) > limit){
                i++;
                while(!maxpq.empty() and maxpq.top().second < i){
                    maxpq.pop();
                }
                while(!minpq.empty() and minpq.top().second < i){
                    minpq.pop();
                }
            }

            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};