class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        // int n=nums.size();
        // int i=0;
        // vector<int>res;
        // while(i<n){
        //     vector<int>temp(1e5+1,-1);
        //     for(int j=n-1;j>=i;j--){
        //         temp[nums[j]]=j;
        //     }
        //     if(temp[0]==-1)break;
        //     int mini=0;
        //     for(int j=0;j<temp.size();j++){
        //         if(temp[j]!=-1){
        //             i=max(i,temp[j]);
        //         }else{
        //             mini=j;
        //             break;
        //         }
        //     }
        //     res.push_back(mini);
        //     i++;
        // }
        // while(i<n){
        //     res.push_back(0);
        //     i++;
        // }
        // return res;

        int n=nums.size();
        vector<int>freq(1e5+1,0);
        vector<int>suff(n,0);
        int mex=0;
        for(int i=n-1;i>=0;i--){
            freq[nums[i]]++;
            while(freq[mex]>0)mex++;
            suff[i]=mex;
        }
        vector<int>res;
        int i=0;
        while(i<n){
            if(suff[i]==0){
                while(i<n){
                    res.push_back(0);
                    i++;
                }
            }else{
                unordered_set<int>st;
                int c=0;
                mex=suff[i];
                while(i<n&&c<mex){
                    if(nums[i]<mex&&!st.count(nums[i])){
                        c++;
                        st.insert(nums[i]);
                    }
                    i++;
                }
                res.push_back(mex);
            }
        }
        return res;
    }
};