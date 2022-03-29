class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       /*for(int i = 1; i <= nums.size()-1; i++)
       {
           int count = 0;
           for(int j = 0; j < nums.size(); j++)
           {
                if(nums[j] == i)
                    count++;
           }
           if(count > 1)
               return i;
       }
        return -1;
        */
        map<int, int> m;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]]++;
        }
        for(auto it: m){
            if(it.second > 1)
                return it.first;
        }
        return -1;
        
        
    }
};