class Solution {
public:

    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        int carry = 0;
        int last = num.size() - 1;

        while(last >= 0) {
            int sum = num[last] + (k % 10) + carry;
            k /= 10;
            num[last] = sum % 10;
            last--;
            carry = sum/10;
        }

        while(k > 0) {
            int sum = (k % 10) + carry;
            k /= 10;

            num.insert(num.begin(), sum%10);
            carry = sum/10;
        }
        if(carry > 0) {
            num.insert(num.begin(), carry);  
        }
        return num;
    }
};