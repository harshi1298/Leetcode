class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i=0;
        int j=arr.size()-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(arr[mid-1]<arr[mid]&&arr[mid+1]<arr[mid])
             return mid;
            else if(arr[mid-1]<arr[mid])
              i=mid+1;
            else
              j=mid;
        }
        return 0;
    }
};