class Solution {
public:
    double trimMean(vector<int>& arr) {
        int k=arr.size();
        int l=k*5/100;
        sort(arr.begin(),arr.end());
        double s=0;
        for(int i=l;i<k-l;i++){
            s=s+arr[i];
        }
        return s/(k-2*l);
    }
};