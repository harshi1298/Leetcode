class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int months[]={31,28,31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        string mini=min(leaveAlice,leaveBob);
        string maxi=max(arriveAlice,arriveBob);
        int stmonth=stoi((maxi.substr(0,2)));
        int endmonth=stoi(mini.substr(0,2));
        if(maxi>mini)return 0;
        if(stmonth==endmonth)return (stoi(mini.substr(3,2))-stoi(maxi.substr(3,2))+1);
        int btwdays=0;
        for(int i=stmonth;i<endmonth-1;i++){
            btwdays+=months[i];
        }
        btwdays+=stoi(mini.substr(3,2));
        cout<<maxi<<" "<<mini<<endl;
        return btwdays-(stoi(maxi.substr(3,2)))+months[stmonth-1]+1;
    }
};