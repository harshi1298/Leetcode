class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourangle=(hour%12)*30+0.5*double(minutes);
        double minuteangle=minutes*6;
        double diff=abs(hourangle-minuteangle);
        return min(diff,360-diff);
    }
};
//60 min 30 degree