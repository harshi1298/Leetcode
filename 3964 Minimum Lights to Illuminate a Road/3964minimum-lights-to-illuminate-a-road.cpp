class Solution {
public:
    int minLights(vector<int>& lights) {
        int n=lights.size();
        vector<int>arr(n+1,0);
        for(int i=0;i<n;i++){
            if(lights[i]>0){
                int mini=max(0,i-lights[i]);
                int maxi=min(n-1,i+lights[i]);
                arr[mini]++;
                arr[maxi+1]--;
            }
        }
        for(int i=1;i<n;i++)arr[i]+=arr[i-1];
        int ans=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                if(i+1<n)arr[i+1]++;
                if(i+2<n)arr[i+2]++;
                ans++;
            }
        }
        return ans;
    }
};