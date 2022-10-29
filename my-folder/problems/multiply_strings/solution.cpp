class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){
            return "0";
        }
        int a[201],b[201];
        int ans[201]={0};
        int i,j,tmp;
        int l1 = num1.size();
        int l2 = num2.size();
        for(i = l1 - 1, j = 0; i >= 0; i--, j++)
        {
            a[j] = num1[i] - '0';
        }
        for(i = l2 - 1, j = 0; i >= 0; i--, j++)
        {
            b[j] = num2[i] - '0';
        }
        for(i = 0; i < l2; i++)
        {
            for(j = 0; j < l1; j++)
            {
                ans[i+j] += b[i] * a[j];
            }
        }
        for(i = 0; i < l1 + l2; i++)
        {
            tmp = ans[i] / 10;
            ans[i] = ans[i] % 10;
            ans[i+1] = ans[i+1] + tmp;
        }
        for(i = l1 + l2; i >= 0; i--)
        {
            if(ans[i] > 0)
                break;
        }
        string result = "";
        for(; i >= 0; i--){
            result += to_string(ans[i]);
        }
        return result;
    }
};