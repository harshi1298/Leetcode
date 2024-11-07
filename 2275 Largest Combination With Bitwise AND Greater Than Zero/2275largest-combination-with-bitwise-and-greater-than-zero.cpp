class Solution {
public:
    int largestCombination(vector<int>& candidates) {
       int maxi=0;
       for(int i=0;i<32;i++){
        int count=0;
         for(int i=0;i<candidates.size();i++){
            if(candidates[i] &1)count++;
            candidates[i]=candidates[i]>>1;
         }
         maxi=max(count,maxi);
       }
       return maxi;
    }
};