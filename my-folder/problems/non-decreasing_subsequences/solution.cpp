class Solution {
public:
    map<vector<int>,int>mp;
    void solve(vector<vector<int>>&res,vector<int>&nums,int x,vector<int>&temp){
    if(temp.size()>=2)
        {   
         mp[temp]++;
         if(mp[temp]>1)
             return;
         res.push_back(temp);
     
        }
        if(x>nums.size())
        {
              return ;
        }
        

        for(int i=x;i<nums.size();i++){
            if(temp.size()>=1)
            {if(nums[i]<temp[temp.size()-1])
                continue;}
            
            temp.push_back(nums[i]);
            solve(res,nums,i+1,temp);
            temp.pop_back();
           
        }
        return;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>temp;
        solve(result,nums,0,temp);
            
        return result;
    }
};