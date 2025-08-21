class Solution {
public:
    int maxArea(vector<int>& h) {
        int j=h.size()-1,ans=0;
        for(int i=0;i<j;){
            if(h[i]<h[j]){
                ans=max(ans,(h[i])*(j-i));
                i++;
            }
            else{
                ans=max(ans,(h[j])*(j-i));
                j--;
            }
        }
        return ans;
    }
};