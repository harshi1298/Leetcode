class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>ans;
        vector<int>close(n);
        close[0]=1;
        close[n-1]=n-2;
        for(int i=1;i<n-1;i++){
            if(abs(nums[i-1]-nums[i])<=abs(nums[i]-nums[i+1])){
                close[i]=i-1;
            }
            else close[i]=i+1;
        }
        int g=0;
        unordered_map<int,int>mapp1,mapp2;
        mapp1[0]=0;
        vector<int>temp1;
        temp1.push_back(0);
        for(int i=1;i<n-1;i++){
            mapp1[i]=g;
            if(close[i]==i-1){
                temp1.push_back(abs(nums[i]-nums[i+1])-1);
                g++;
            }
        }
        mapp1[n-1]=g;
        for(int i=1;i<temp1.size();i++){
            temp1[i]+=temp1[i-1];
        }
        mapp2[0]=0;
        g=0;
        vector<int>temp2;
        temp2.push_back(0);
        for(int i=n-2;i>0;i--){
            mapp2[i]=g;
           if(close[i]==i+1){
             temp2.push_back(abs(nums[i]-nums[i-1])-1);
             g++;
           }
        }
        mapp2[0]=g;
        for(int i=1;i<temp2.size();i++)temp2[i]+=temp2[i-1];
        for(auto it: queries){
            int st=it[0],end=it[1];
            int an;
            if(st<end){
               int stg=mapp1[st];
               int endg=mapp1[end];
               an=end-st;
               an+=temp1[endg]-temp1[stg];
            }
            else{
               int stg=mapp2[st];
               int endg=mapp2[end];
               an=st-end;
               an+=temp2[endg]-temp2[stg];
            }
            ans.push_back(an);
        }
        return ans;
    }
};