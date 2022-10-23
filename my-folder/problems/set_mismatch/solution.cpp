class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int, int> m;
        for(auto it: nums)
            m[it]++;
        int missingNumber = -1, duplicateNumber = -1;
        for(int i = 1; i <= nums.size(); i++){
            if(m[i] == 0)
                missingNumber = i;
            if(m[i] == 2)
                duplicateNumber = i;
        }
        vector<int> ans{duplicateNumber, missingNumber};
        return ans;
    }
};