class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        map<int, vector<int>> m;
        for(auto it: nums){
            m[it % space].push_back(it);
        }
        int maxi = INT_MIN;
        int ans = INT_MAX;
        for(auto it: m){
            sort(it.second.begin(), it.second.end());
            int size = it.second.size();
            if(size > maxi){
                maxi = size;
                ans = it.second[0];
            } else if(size == maxi){
                ans = min(ans, it.second[0]);
            }
        }
        return ans;
        
        
    }
};