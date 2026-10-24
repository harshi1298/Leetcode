class Solution {
    public boolean isValid(String s) {
        int n=s.length();
        Deque<Character> st=new ArrayDeque<>();
        for(int i=0;i<n;i++){
            if(s.charAt(i)=='(' || s.charAt(i)=='{'  || s.charAt(i)=='['){
                st.push(s.charAt(i));
            }
            else if(! (!st.isEmpty()  && ((st.peek()=='(' && s.charAt(i)==')' ) ||( st.peek()=='{' && s.charAt(i)=='}' ) || (st.peek()=='[' && s.charAt(i)==']')))) {
                return false;
            }
            else st.pop();
        }
        return st.isEmpty();
    }
}