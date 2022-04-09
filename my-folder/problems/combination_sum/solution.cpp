class Solution {
public:
    void helper(vector<int> &candidates, int target, vector<vector<int>> &ans, vector<int> &v, int index){
        if(index == candidates.size()){
            if(target == 0){
                ans.push_back(v);
            }
            return;
        }
        
        if(candidates[index] <= target){
            v.push_back(candidates[index]);
            helper(candidates, target - candidates[index], ans, v, index);
            v.pop_back();
        }
        helper(candidates, target, ans, v, index + 1);
    }
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        vector<vector<int>> ans;
        helper(candidates, target, ans, v, 0);
        return ans;
    }
};