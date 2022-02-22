class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size()-1;
        int sum = 0;
        for(int i = 0; i < columnTitle.size(); i++)
        {
            int rem = columnTitle[i] - 'A';
            rem++;
            sum += pow(26,n)*rem;
            n--;
        }
        return sum;
    }
};