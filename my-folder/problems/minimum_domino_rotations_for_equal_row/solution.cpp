class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        map<int, int> m;
        for(int i = 0; i < tops.size(); i++){
            m[tops[i]]++;
            m[bottoms[i]]++;
        }
        
        int maxi = INT_MIN;
        int maxtimes = -1;
        for(auto it: m)
        {
            if(it.second > maxi)
            {
                maxi = it.second;
                maxtimes = it.first;
            }
        }
        
        int commontimes = 0;
        int topcount = 0, bottomcount = 0;
        for(int i = 0; i < tops.size(); i++)
        {
            if(tops[i] == maxtimes && bottoms[i] == maxtimes)
            {
                commontimes++;
            }
            if(tops[i] == maxtimes)
            {
                topcount++;
            }
            if(bottoms[i] == maxtimes)
            {
                bottomcount++;
            }
        }
    
        if(maxi - commontimes != tops.size())
        {
            return -1;
        }
        return min(topcount, bottomcount) - commontimes;
        
    }
        
};