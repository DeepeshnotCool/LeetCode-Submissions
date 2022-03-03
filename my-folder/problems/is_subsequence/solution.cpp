class Solution {
public:  
  
   
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while(i < s.size() && j < t.size())
        {
            if(s[i] == t[j])
            {
                i++;
            }
            j++;
        }
        if(i == s.size())
            return true;
        return false;
        
        
        
        
        
        
        
        
        
        
        /*
        if(s.size() == 1)
        {
            for(int i = 0; i < t.size(); i++)
            {
                if(s[0] == t[i])
                    return true;
            }
             return false;
        }
        map<char, int> m1;
        map<char, int> m2;
        for(int i = 0; i < s.size(); i++)
        {
            m1[i] = s[i];
        }
        for(int i = 0; i < t.size(); i++)
        {
            m2[t[i]] = i;
        }
        int prev = INT_MIN;
        for(auto it: m1)
        {
            if(it.first == 0 && m2[it.second] == 0)
            {
                if(t[0] != it.second)
                    return false;
            }
            if(it.first != 0 && m2[it.second] == 0)
            {
                return false;
            }
            else
            {
                if(m2[it.second] >= prev)
                    prev = m2[it.second];
                else
                    return false;
            }
        }
        return true;
        */
    }
};





