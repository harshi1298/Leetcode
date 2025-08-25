class Solution {
public:
    int earliestFullBloom(vector<int>& pt, vector<int>& gt) {
        vector<pair<int,int>>temp;
        int n=gt.size(),ans=0;
        for(int i=0;i<n;i++){
            temp.push_back(make_pair(gt[i],i));
        }
        sort(temp.begin(), temp.end(), greater<pair<int,int>>());
        vector<int>lt(n,0);
        for(int i=0;i<n;i++){
            int idx=temp[i].second;
            ans+=pt[idx];
            lt[idx]=ans;
        }
        for(int i=0;i<n;i++){
            ans=max(ans,lt[i]+gt[i]);
        }
        return ans;
    }
};