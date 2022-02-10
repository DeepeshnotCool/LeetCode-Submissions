class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        int maxi = INT_MIN;
        int maxe = 0;
        for(auto it : m)
        {
            maxi = max(maxi,it.second);
            if(maxi == it.second)
                maxe = it.first;
        }
        return maxe;
    }
};