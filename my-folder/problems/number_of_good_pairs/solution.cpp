class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        map<int, int> m;
        for(int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        int sum = 0;
        for(auto it : m)
        {
            if(it.second < 2)
                continue;
            sum += ((it.second) * (it.second - 1))/2; 
        }
        return sum;
    }
};