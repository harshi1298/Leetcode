class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>ac(51,0),bc(51,0);
        int n=A.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            ac[A[i]]++;
            bc[B[i]]++;
            int count=0;
            for(int j=1;j<=50;j++){
                if(ac[j]==bc[j] && ac[j]!=0)count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};