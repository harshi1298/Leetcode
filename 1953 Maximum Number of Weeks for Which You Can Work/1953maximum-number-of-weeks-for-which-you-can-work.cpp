class Solution {
public:
    long long numberOfWeeks(vector<int>& mile) {
        long long sum=0;
        for(auto it : mile)sum+=it;
        long long maxi=*max_element(mile.begin(),mile.end());
        if(maxi>sum-maxi)return 2*(sum-maxi)+1;
        return sum;
    }
};