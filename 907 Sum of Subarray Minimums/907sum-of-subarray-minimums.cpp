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

public:
    int sumSubarrayMins(vector<int>& arr) {
        long long ans=0;
        int size=arr.size();
        vector<int>pse(size);
        vector<int>nse(size);
        formPSE(arr,pse,size);
        formNSE(arr,nse,size);
        for(int i=0;i<size;i++){
            long long left=i-pse[i];
            long long right=nse[i]-i;
            ans=(ans+(left*(right*arr[i])%modulo)%modulo)%modulo;
        }
        return ans;
    }
};