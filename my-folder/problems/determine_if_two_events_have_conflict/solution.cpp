class Solution {
public:
    
    int time(string s)
    {
        string h=s.substr(0,2);
        string m=s.substr(3,5);
        int hour=stoi(h);
        int min=stoi(m);
        int t=hour*60+min;
        return t;
        
    }
    
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int time1,time2,time3,time4;
        time1=time(event1[0]);
        time2=time(event1[1]);
        time3=time(event2[0]);
        time4=time(event2[1]);
        if(time3>=time1&&time3<=time2)
            return true;
        if(time1>=time3&&time1<=time4)
            return true;
        return false;
    }
};