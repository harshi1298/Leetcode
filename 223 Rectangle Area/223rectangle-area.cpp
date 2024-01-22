class Solution{
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int l1=ay2-ay1;
        int l2=by2-by1;
        int b1=ax2-ax1;
        int b2=bx2-bx1;
        int sum=b1*l1;
        sum+=b2*l2;
        if(bx1>ax2 || by1>ay2 || bx2<ax1 || by2<ay1){
            return sum;
        }
        int cx1=max(ax1,bx1);
        int cx2=min(ax2,bx2);
        int cy1=max(ay1,by1);
        int cy2=min(ay2,by2);
        sum-=((cx2-cx1)*(cy2-cy1));
        return sum;
        
    }
};