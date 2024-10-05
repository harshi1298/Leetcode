class Solution {
public:
    int numberOfSubstrings(string s) {
        int arr[3]={-1,-1,-1};
        int ans=0;
        for(int i=0;i<s.length();i++){
            arr[s[i]-'a']=i;
            if(arr[0]!=-1 && arr[1]!=-1 && arr[2]!=-1){
                int k=min(arr[0],min(arr[1],arr[2]));
                ans=ans+(k+1);
           }
        }
        return ans;       
    }
};