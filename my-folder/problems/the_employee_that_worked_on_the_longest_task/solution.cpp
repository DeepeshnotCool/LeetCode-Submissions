class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int diff = 0;
        int maxi = INT_MIN;
        int ans = 0;
        for(int i = 0; i < logs.size(); i++){
            diff = logs[i][1] - diff;
            cout<<diff<<endl;
            if(diff > maxi){
                maxi = diff;
                ans = logs[i][0];
            }
            else if(diff == maxi){
                ans = min(ans,logs[i][0]);
            }
            diff = logs[i][1];
        }
        return ans;
        
    }
};