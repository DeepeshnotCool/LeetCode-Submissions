class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        long long count = 0;
        long long sum = 0;
        for(auto it : nums){
            count += it;
            if(count > 0)
                sum++;
            else
                break;
        }
        return sum;
    }
};