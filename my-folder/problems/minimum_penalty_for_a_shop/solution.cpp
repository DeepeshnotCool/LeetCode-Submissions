class Solution {
public:
    int bestClosingTime(string customers) {
        int county = 0, countn = 0;
        int n = customers.size();
        for(int i = 0; i < n; i++){
            if(customers[i] == 'Y')
                county++;
            else
                countn++;
        }
        
        if(county == n)
            return n;
        if(countn == n)
            return 0;
        int ans = county, result = 0;
        for(int i = 0; i < n; i++){
            if(customers[i] == 'Y')
                county--;
            else
                county++;
            if(ans > county){
                ans = county;
                result = i + 1;
            }
        }
        return result;
    }
};
