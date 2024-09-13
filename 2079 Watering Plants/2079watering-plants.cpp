class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int k=capacity;
        int ans=0;
        for(int i=0;i<plants.size();i++){
            if(k>=plants[i]){
                ans++;
                k=k-plants[i];
            }
            else{
                ans=ans+2*i+1;
                k=capacity-plants[i];
            }
        }
        return ans;
    }
};