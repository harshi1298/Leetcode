class Solution {
public:
    int maxDistance(string moves) {
        int x=0,y=0;
        int count=0;
        for(auto it : moves){
            if(it=='U')y--;
            else if (it=='D')y++;
            else if (it=='L')x--;
            else if(it=='R')x++;
            else count++;
        }
        return abs(x)+abs(y)+count;
    }
};