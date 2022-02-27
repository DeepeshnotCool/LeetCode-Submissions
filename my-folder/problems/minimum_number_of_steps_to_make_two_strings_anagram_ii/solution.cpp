class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int> m1;
       // map<char,int> m2;
        for(int i = 0; i < s.size(); i++)
        {
            m1[s[i]]++;
        }
        for(int i = 0; i < t.size(); i++)
        {
            m1[t[i]]--;
        }
        int count = 0;
        for(auto it : m1)
        {
            if(it.second < 0)
            {
                count += (it.second*-1);
                continue;
            }
            count += it.second;
        }
         return count;
//         if(s.size() >= t.size())
//         {
//             for(auto it : m1)
//             {
//                 count += abs(it.second - m2[it.first]);
//             }
//             for(int i = 0; i < t.size(); i++)
//             {

//                 count += abs(m2[t[i]] - m1[t[i]]);
//             }
//         }
//         else
//         {
//             for(auto it : m2)
//             {
//                 count += abs(it.second - m1[it.first]);
//             }
//             for(int i = 0; i < s.size(); i++)
//             {

//                 count += abs(m2[t[i]] - m1[t[i]]);
//             }
//         }
//         return count;
    }
};