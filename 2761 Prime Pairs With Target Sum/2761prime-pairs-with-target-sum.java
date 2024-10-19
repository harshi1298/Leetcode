class Solution {
    public List<List<Integer>> findPrimePairs(int n) {
  List<List<Integer>>  list=new ArrayList<>();


   for(int i=2;i<=n/2;i++){
    if(prime(i)&& prime(n-i)){
        List<Integer>pair= new ArrayList<>();
        pair.add(i);
        pair.add(n-i);
        list.add(pair);
        
            
        }
    }
    return list;
   }
        
    
    static boolean prime(int n){
        if(n<2){
            return false;
        }
             for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    }
