class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int> v;
        int result = 0, sign = 1;;
        while(n != 0){
            v.push_back(n % 10);
            n /= 10;
        }
        reverse(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++){
            result += (sign * v[i]);
            sign *= (-1);
        }
        return result;
    }
};