#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>


class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
      unordered_map<int,int>mapp;
      int n=nums1.size();
      for(int i=0;i<n;i++){
        mapp[nums1[i]]=i;
      }
      ordered_set st;
      long long ans=0;
      for(int j=0;j<n;j++){
        int idx=mapp[nums2[j]];
        long long l_el=st.order_of_key(idx);
        long long r_el=n-1-idx-(st.size()-l_el);
        ans+=(l_el*r_el);
        st.insert(idx);
      }
      return ans;
    }
};