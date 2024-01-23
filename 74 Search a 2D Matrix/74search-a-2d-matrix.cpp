class Solution {
public:
    int binarySearchrow(vector<vector<int>> matrix, int target,int row,int col){
        int i=0;
        int j=col;
        int ans=-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(matrix[row][mid]<target){
                ans=mid;
                i=mid+1;
            }
            else if(matrix[row][mid]>target){
                j=mid-1;
            }
            else{
                ans= mid;
break;}
        }
        return ans;
    }
    int binarySearchcol(vector<vector<int>> matrix, int target,int col,int row){
        int i=0;
        int j=row;
        int ans=-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(matrix[mid][col]<target){
                ans=mid;
                i=mid+1;
            }
            else if(matrix[mid][col]>target){
                j=mid-1;
            }
            else{
                ans= mid;
            break;}
        }
        return ans;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size()-1;
        int c=matrix[0].size()-1;
        int p=binarySearchcol(matrix,target,0,r);
        if(p==-1)
            return false;
        int q=binarySearchrow(matrix,target,p,c);
        if(matrix[p][q]==target)
            return true;
        return false;
        
    }
};