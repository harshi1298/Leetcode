class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int i=0;i<asteroids.size();i++){
            int flag=0;
           if(!st.empty() && st.top()>=0 && asteroids[i]<0){
            while(!st.empty() && st.top()>0){
                if(st.top()<asteroids[i]*-1)st.pop();
                else if(st.top()<=asteroids[i]*-1){
                    flag=1;
                    st.pop();
                    break;
                }
                else{
                    flag=1;
                    break;
                }
            }
           }
           if(!flag)
            st.push(asteroids[i]);
        }
        int k=st.size();
         vector<int>ans(k);
         k--;
        while(!st.empty()){
            ans[k--]=st.top();
            st.pop();
        }
        return ans;
    }
};