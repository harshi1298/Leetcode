class Solution {
private:
   void merge(vector<int> &nums,int i,int mid,int j){
    int size1=mid-i+1,size2=j-mid,k=0, s=i,m,n;
    int arr1[size1];
    int arr2[size2];
    while(k<size1){
        arr1[k++]=nums[i++];
    }
    k=0;
    while(k<size2) arr2[k++]=nums[i++];
    for( m=0,n=0;m<size1&&n<size2;){
        if(arr1[m]<arr2[n]){
            nums[s++]=arr1[m++];
        }
        else nums[s++]=arr2[n++];
    }
    while(m<size1)nums[s++]=arr1[m++];
    while(n<size2)nums[s++]=arr2[n++];
   }
   void mergesort(vector<int> &nums,int i,int j){
    if(i>=j) return;
    int mid=i+(j-i)/2;
    mergesort(nums,i,mid);
    mergesort(nums,mid+1,j);
    merge(nums,i,mid,j);
   }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
   return nums;
    }
};