class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int n=a.size();
        int i=0,j=0;
        while(j<n && i<n){
            if(a[i]!=0) i++;
            else{
                if(a[j]!=0 && i<j) swap(a[j],a[i]);
                j++;
            }
        }
       
    }
};