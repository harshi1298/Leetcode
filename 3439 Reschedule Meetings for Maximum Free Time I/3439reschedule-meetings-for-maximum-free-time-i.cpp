class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
         int end=0;
        int n=startTime.size();
        vector<int> arr;
        for(int i=0;i<n;i++){
            
            arr.push_back(startTime[i]-end);
            end=endTime[i];
        }
        if(eventTime - endTime[n-1] >0){
            arr.push_back(eventTime - endTime[n-1]);
            cout<<eventTime - endTime[n-1]<<endl;
        }
        cout<<arr.size()<<endl;
        int i=0;
        int j=0;
        long long  sum=0;
        long long  mx=0;
        int s=arr.size();
        while(j<s){
            if(j<k+1){
                sum+=arr[j];
                j++;
            }
            else{
                sum-=arr[i];
                i++;
                if(j<s) sum+=arr[j];
                j++;
            }
            mx=max(mx,sum);
        }
        return mx;
    }
};