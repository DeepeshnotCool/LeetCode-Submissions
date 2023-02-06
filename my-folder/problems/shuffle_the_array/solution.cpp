class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i = 0, j = n;
        vector<int> ans;
        bool flag = false;
        for(int k = 0; k < 2*n; k++){
            if(flag){
                ans.push_back(nums[j]);
                j++;
            } else{
                ans.push_back(nums[i]);
                i++;
            }
            flag = !flag;
        }
        return ans;
    }
};