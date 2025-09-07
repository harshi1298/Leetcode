class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        for(int i=0;i<n/2;i++)ans.push_back(i+(-n));
        int j=ans.size()-1;
        if(n%2){
            ans.push_back(0);
        }
        while(j>=0){
            ans.push_back(-ans[j]);
            j--;
        }
        return ans;
    }
};