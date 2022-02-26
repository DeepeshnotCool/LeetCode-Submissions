class Solution {
public:
    double average(vector<int>& salary) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int sum = 0;
        for(int i = 0; i < salary.size(); i++)
        {
            sum += salary[i];
            if(maxi < salary[i])
                maxi = salary[i];
            if(mini > salary[i])
                mini = salary[i];
        }
        return (double)(sum - (maxi + mini))/(salary.size()-2);
        
    }
};