class Solution {
public:
    //int count;
    int helper(vector<int> &prices, int min, vector<int> &newarr, int index){
        //count++;
        if(index >= prices.size()){
            return 0;
        }
        if(newarr[index] != -1){
            return newarr[index];
        }
        if(prices[index] < min){
            min = prices[index];
        }
        
        int temp = prices[index] - min;
        int ans = helper(prices, min, newarr, index+1);
        return newarr[index] = max(ans, temp);
    }
    
    
    
    int maxProfit(vector<int>& prices) {
        /*int maxi = INT_MIN;
        for(int i = 0; i < prices.size(); i++)
        {
            int a = prices[i];
            for(int j = i+1; j < prices.size(); j++)
            {
                maxi = max(prices[j]-a,maxi);
            }
        }
        return max(maxi,0);
        */
        vector<int> newarr(prices.size() + 1, -1);
        int index = 0;
        int ans = helper(prices, prices[0], newarr, index);
        //cout<<count;
        return ans;
    }
};