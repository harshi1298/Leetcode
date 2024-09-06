class Solution {
private: 
   int modulo = 1e9 + 7;

   void formPSE(vector<int>arr,vector<int> &pse,int size){
    stack<int>st;
        for(int i=0;i<size;i++){
            while(!st.empty() && arr[st.top()]>=arr[i])st.pop();
            if(!st.empty()){
                pse[i]=st.top();
            }
            else pse[i]=-1;
            st.push(i);
        }
   }
         void formNSE(vector<int>arr,vector<int> &nse,int size){
        stack<int>st;
        for(int i=size-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i])st.pop();
            if(!st.empty()){
                nse[i]=st.top();
            }
            else nse[i]=size;
            st.push(i);
        }
   }

      void formPGE(vector<int>arr,vector<int> &pge,int size){
    stack<int>st;
        for(int i=0;i<size;i++){
            while(!st.empty() && arr[st.top()]<=arr[i])st.pop();
            if(!st.empty()){
                pge[i]=st.top();
            }
            else pge[i]=-1;
            st.push(i);
        }
   }
         void formNGE(vector<int>arr,vector<int> &nge,int size){
        stack<int>st;
        for(int i=size-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<arr[i])st.pop();
            if(!st.empty()){
               nge[i]=st.top();
            }
            else nge[i]=size;
            st.push(i);
        }
   }
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans=0;
        int size=nums.size();
        vector<int>pse(size);
        vector<int>nse(size);
        vector<int>pge(size);
        vector<int>nge(size);
        formPSE(nums,pse,size);
        formNSE(nums,nse,size);
        formPGE(nums,pge,size);
        formNGE(nums,nge,size);
        for(int i=0;i<size;i++){
            long long left=i-pse[i];
            long long right=nse[i]-i;
            ans=ans-(left*(right*nums[i]));
        }
        for(int i=0;i<size;i++){
            long long left=i-pge[i];
            long long right=nge[i]-i;
            ans=ans+(left*(right*nums[i]));
        }
        return ans;
    }
};