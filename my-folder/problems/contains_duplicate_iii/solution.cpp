class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        vector<pair<int, int>> vp(nums.size());
        for(int i = 0; i < nums.size(); i++){
           vp[i].first = nums[i];
           vp[i].second = i;
        }
        sort(vp.begin(), vp.end());
        for(int i = 0; i < vp.size(); i++){
            for(int j = i+1; j < vp.size(); j++){
                if(abs(vp[i].first - vp[j].first) <= valueDiff){
                    if(abs(vp[i].second - vp[j].second) <= indexDiff)
                        return true;
                    
                } else{
                    break;
                }
            }
        }
        return false;
    }
};