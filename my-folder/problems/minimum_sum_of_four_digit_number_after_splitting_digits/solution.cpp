class Solution {
public:
    int minimumSum(int num) {
        vector<int> n;
        while(num != 0)
        {
            n.push_back(num%10);
            num/=10;
        }
        sort(n.begin(),n.end());
        int first_no = (n[0]*10)+n[2];
        int second_no = (n[1]*10)+n[3];
        return first_no + second_no;
    }
};