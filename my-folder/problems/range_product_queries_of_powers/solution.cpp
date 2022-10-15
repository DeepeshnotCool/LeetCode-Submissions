class Solution {
public:
    
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
         int mod=1e9+7;
        vector<int> power;
       
        for(int i=0;i<31;i++)
        {
            if(n&(1<<i))
            {
                power.push_back(pow(2,i));
            }
        }
        vector<int> ans;
        
        for(int i=0;i<queries.size();i++)
        {
            int temp=1;
            for(int j=queries[i][0];j<=queries[i][1];j++)
            {
                temp=(1LL*temp*power[j])%mod;
            }
            ans.push_back(temp%mod);
        }
        return ans;
    }
};