class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int maxi = INT_MIN;
        for(int i = 0; i < special.size(); i++){
            if(i == 0)
                maxi = max(maxi, special[i] - bottom);
            else
                maxi = max(maxi, special[i] - special[i-1] - 1);
        }
        maxi = max(maxi, top - special[special.size()-1]);
        return maxi;
    }
};