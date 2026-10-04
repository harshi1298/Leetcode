class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>>ans=new ArrayList<>();
        HashMap<String,List<String>>mapp=new HashMap<>();
        int n=strs.length;
        for(int i=0;i<n;i++){
            char[] arr=strs[i].toCharArray();
            Arrays.sort(arr);
            String key = new String(arr);
            if(!mapp.containsKey(key)){
                mapp.put(key,new ArrayList<>());
            }
            mapp.get(key).add(strs[i]);
        }
        for(Map.Entry<String,List<String>> entry :mapp.entrySet()){
            ans.add(entry.getValue());
        }
        return ans;
    }
}