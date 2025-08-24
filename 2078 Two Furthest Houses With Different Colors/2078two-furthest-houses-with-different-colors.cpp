class Solution {
public:
    int maxDistance(vector<int>& col) {
        int n=col.size();
        int ans=0,i=0,j=n-1;
        while(col[i]==col[j])i++;
        ans=max(ans,j-i);
        while(col[j]==col[0])j--;
        ans=max(ans,j);
        return ans;
    }
};