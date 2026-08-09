class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(),prices.end(),greater<int>());
        sort(discounts.begin(),discounts.end(),greater<int>());
        double ans=0;
        int i;
        for(i=0;i<min(prices.size(),discounts.size());i++){
            double price=prices[i];
            double per=100-discounts[i];
            ans+=price*per/100;
        }
        while(i<prices.size()){
            ans+=prices[i];
            i++;
        }
        return ans;
    }
};