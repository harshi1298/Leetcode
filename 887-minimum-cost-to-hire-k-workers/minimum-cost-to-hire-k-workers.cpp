class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,double>>arr;
        int n=wage.size();
        for(int i=0;i<n;i++){
            arr.push_back({(double)(wage[i])/(double)(quality[i]),quality[i]});
        }
        sort(arr.begin(),arr.end());
        double ans=DBL_MAX;
        double sum=0;
        priority_queue<double>pq;
        for(auto it : arr){
            double ratio=it.first;
            double q=it.second;
            sum+=q;
            pq.push(q);
            while(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size()==k)ans=min(ans,sum*ratio);
        }
        return ans;
    }
};