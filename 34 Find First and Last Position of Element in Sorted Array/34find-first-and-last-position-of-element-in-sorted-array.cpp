class Solution {
public:
         int first(vector<int>&arr,int target,int j){
             int i=0,mid,ans,l=0;
             while(i<=j){
        mid=i+(j-i)/2;
        if(arr[mid]==target){
             ans=mid;
             l=1;
            j=mid-1;
        }
        else if(arr[mid]>target)
          j=mid-1;
        else
         i=mid+1;
    }
    if(l)
    return ans;
    else
         return -1;
         }
 int last(vector<int>& arr,int target,int j){
        int i=0,mid,ans,l=0;
       while(i<=j){
        mid=i+(j-i)/2;
        if(arr[mid]==target){
            ans=mid;
            cout<<mid;
            l=1;
            i=mid+1;
        }
        else if(arr[mid]>target)
          j=mid-1;
        else
         i=mid+1;
    }
    if(l)
    return ans;
    else
     return -1;
         }
    vector<int> searchRange(vector<int>& arr, int target) {
    int i=0;
    int j=arr.size()-1;
    vector<int>ans(2);
    ans[0]=first(arr,target,j);
    ans[1]=last(arr,target,j);
    return ans;
    }
};