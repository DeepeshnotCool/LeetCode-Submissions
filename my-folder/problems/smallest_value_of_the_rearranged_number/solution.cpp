class Solution {
public:
    long long smallestNumber(long long num) {
        vector<int> v;
        long long temp = num;
        if(num < 0)
            num *= -1;
        while(num != 0)
        {
            v.push_back(num % 10);
            num /= 10;
        }
        if(temp < 0)
        {
            sort(v.begin(),v.end(),greater<int>());
            long long ans = 0;
            int n = v.size()-1;
            for(int i = 0; i < v.size(); i++)
            {
                ans += pow(10,n)*v[i];
                n--;
            }
            return ans*-1;
        }
        else
            sort(v.begin(),v.end());
      
        long long countZero = 0;
        for(int i = 0; i < v.size(); i++)
        {
            if(v[i] == 0)
                countZero++;
        }
        vector<int> ansV;
        for(int i = 0; i < v.size(); i++)
        {
            if(v[i] != 0)
            {
                ansV.push_back(v[i]);
                break;
            }   
        }
        while(countZero--)
            ansV.push_back(0);
        for(int i = ansV.size(); i < v.size(); i++)
        {
            ansV.push_back(v[i]);   
        }
        long long ans = 0;
        int n = ansV.size()-1;
        for(int i = 0; i < ansV.size(); i++)
        {
            ans += pow(10,n)*ansV[i];
            n--;
        }
        return ans;
        
    }
};