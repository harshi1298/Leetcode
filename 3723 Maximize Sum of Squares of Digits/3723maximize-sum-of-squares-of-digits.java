class Solution {
    public String maxSumOfSquares(int num, int sum) {
        
        StringBuilder sb= new StringBuilder();
        for(int i=0;i<num;i++){
            if(sum>8){
                sb.append(9);
                sum-=9;
            }else if(sum>0){
                sb.append(sum);
                sum=0;
                
            }else{
                sb.append(0);
            }

        }  
        if(sum>0)return "";
        return sb.toString();      
    }
}