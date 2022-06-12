class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
       int prev = 0;
        double result = 0;
        for(int i = 0; i < brackets.size(); i++){
            int mini = min(brackets[i][0], income);
            result += (mini - prev)*brackets[i][1]*1.0/100*1.0;
            if(brackets[i][0] > income)
                break;
            prev = brackets[i][0];

        }
        return result;
    }
};