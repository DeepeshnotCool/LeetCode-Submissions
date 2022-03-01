class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size() != s2.size())
            return false;
        int leftIndex = -1;
        int rightIndex = -1;
        int count = 0;
        for(int i = 0; i < s1.size(); i++)
        {
            if(s1[i] != s2[i])
            {
                if(count >= 1)
                    rightIndex = i;
                else
                    leftIndex = i;
                count++;
            }
        }
        if(leftIndex == -1 && rightIndex == -1)
            return true;
        else if(leftIndex == -1 || rightIndex == -1)
            return false;        
        if(count == 2)
        {
            if(s1[leftIndex] == s2[rightIndex] && s1[rightIndex] == s2[leftIndex])
            {
                return true;
            }
        }
        return false;
    }
};