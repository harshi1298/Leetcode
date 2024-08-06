class Solution {
private:
   bool ispossible(vector<int> piles,int h,int mid){
    if( mid==0)return false;
    for(int i=0;i<piles.size();i++){
        if(piles[i]<=mid)h--;
        else {
            if(piles[i]%mid!=0){
                int k=piles[i]/mid+1;
                h-=k;
            }
            else{
               int k=piles[i]/mid;
                h-=k; 
            }
        }
    }
    if(h>=0) return true;
    else return false;
   }
   
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans=INT_MAX;
         int right = *max_element(piles.begin(), piles.end());
        int i=0;
        int j=right;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(!ispossible(piles,h,mid)){
                i=mid+1;
            }
            else {
                 ans=min(ans,mid);
                 j=mid-1;
            }
        }
        return ans;
    }
};