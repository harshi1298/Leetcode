class Solution {
    public int numOfUnplacedFruits(int[] fruits, int[] baskets) {
    int f1=fruits.length;
    int b1=baskets.length;

    boolean[] visited=new boolean[b1];
    for(int i=0;i<f1;i++){
    int j=0;
    while(j<b1){
     if(!visited[j] &&  fruits[i]<=baskets[j]){
     visited[j]=true;
     break;
     }
     j++;
    }
    }
    int count=0;
    for(boolean b  : visited){
    if(b==false)count++;
    }
  return count;
        
    }
}