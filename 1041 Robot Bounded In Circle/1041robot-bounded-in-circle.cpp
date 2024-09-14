class Solution {
public:
    bool isRobotBounded(string instructions) {
     bool north=true;
     bool east=false;
     bool west=false;
     bool south=false;  
     int magnitude=0;
     pair<int,int>crd={0,0};
     for(auto i:instructions){
        if(north){
            if(i=='G')crd.second++;
            else if(i=='L'){
                north=false;
                west=true;
            }
            else{
               north=false;
               east=true; 
            }
        }
        else if(south){
            if(i=='G'){
                crd.second--;
            }
            else if(i=='L'){
                east=true;
                south=false;
            }
            else{
                west=true;
                south=false;
            }
        }
        else if(east){
           if(i=='G'){
                crd.first++;
            }
            else if(i=='L'){
                east=false;
                north=true;
            }
            else{
                south=true;
                east=false;
            }
        }
        else{
           if(i=='G'){
                crd.first--;
            }
            else if(i=='L'){
                west=false;
                south=true;
            }
            else{
                north=true;
                west=false;
            }
        }
     }
     if(crd.first==0 && crd.second==0)return true;
     if(!north) return true;
     return false;
    }
};