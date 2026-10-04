class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n=s.length();
        HashMap<Character,Integer>mapp=new HashMap<>();
        int l=0,ans=0;
        for(int i=0;i<n;i++){
            while(l<i && mapp.containsKey(s.charAt(i))){
                mapp.put(s.charAt(l),mapp.get(s.charAt(l))-1);
                if(mapp.get(s.charAt(l))==0)mapp.remove(s.charAt(l));
                l++;
            }
            mapp.put(s.charAt(i),mapp.getOrDefault(s.charAt(i),0)+1);
            ans=Math.max(ans,i-l+1);
        }
        return ans;
    }
}