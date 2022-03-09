class Solution {
public:
    double angleClock(int hour, int minutes) {
        double mih = (double)minutes/12;
        double anglediff = mih * 6;
        cout<<mih<<" "<<anglediff<<endl;
        map<int,double> m;
        double angle = 30; 
        for(int i = 1; i <= 12; i++)
        {
             m[i] = angle;
            angle += 30;
        }
        m[12] = 0;
        double mindiff = (minutes%5) * 6;
        double temp = min(abs(m[minutes/5] - m[hour]), 360 - abs(m[minutes/5] - m[hour]));
        if(temp == 180)
        {         
            if(anglediff < mindiff)
            {
                double temp1 = anglediff;
                anglediff = mindiff;
                mindiff = temp1;
            }
        }
        else
        {
            if(abs(m[minutes/5] - m[hour]) > 360 - abs(m[minutes/5] - m[hour]))
            {
                if(m[hour] < m[minutes/5])
                {
                    double temp1 = anglediff;
                    anglediff = mindiff;
                    mindiff = temp1;
                }
            }
            else
            {
                if(m[hour] > m[minutes/5])
                {
                    double temp1 = anglediff;
                    anglediff = mindiff;
                    mindiff = temp1;
                }
            }
        }
        cout<<temp<<endl;
        cout<<anglediff<<" "<<mindiff;
        return abs(temp - anglediff + mindiff);
    }
};