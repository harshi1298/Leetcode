class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;  
        for(int i=0;i<k;i++){
            sum=sum+cardPoints[i];
        }
        int ans=sum;
        int l=k-1;
        for(int j=0;j<k;j++){
            sum=sum-cardPoints[l];
            l--;
            sum=sum+cardPoints[cardPoints.size()-j-1];
            ans=max(ans,sum);
        }
        return ans;
    }
};