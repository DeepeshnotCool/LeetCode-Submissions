class Solution {
public:
    int countTime(string time) {
        char ch='?';
        int ans=0;
        set<string> st;
        for(int i=0; i<=2; i++) 
        {
            string s = time;
            if(time[0] == ch)
            {
                s[0] = (char)(i+48);
        
            }
            int temp = 9;
            if(i == 2)
            temp = 3;
       
            for(int j=0; j <= temp; j++)
            {
            
                if(time[1] == ch)
                {
                    s[1] = (char)(j+48);

                }
                for(int k=0; k<=6; k++)
                {
                    if(time[3] == ch)
                    {
                        s[3] = (char)(k+48);
                    
                    }
                    for(int l=0; l<=9; l++)
                    {
                        if(time[4] == ch)
                        {
                            s[4] = (char)(l+48);
                        }
                        string hour=s.substr(0,2);
                        int h=stoi(hour);
                        string min=s.substr(3,5);
                        int m=stoi(min);
                        if(h>=0&&h<=23&&m>=0&&m<=59)
                        st.insert(s);
                    }
                } 
            }
        }
        return st.size();
    }
};