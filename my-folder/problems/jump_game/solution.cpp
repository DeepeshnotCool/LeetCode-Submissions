class Solution {
public:
    bool helper(vector<int> &nums, int s, vector<int> &visited){
        if(s < 0 || s >= nums.size() || visited[s] == 1)
            return false;
        if(s == nums.size() - 1){
            return true;
        }
        visited[s] = 1;
        for(int i = s; i <= s + nums[s]; i++){
            if(helper(nums, i, visited))
               return true;
        }
        return false;
        
    }
    bool canJump(vector<int>& nums) {
        vector<int> visited(nums.size(), 0);
       // vector<int> memo(nums.size()+1, -1);
        return helper(nums, 0, visited);
    }
};