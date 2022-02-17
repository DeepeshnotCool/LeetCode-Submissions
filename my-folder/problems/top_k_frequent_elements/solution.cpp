class Solution {
public:
    
    static bool cmp(pair<int,int>& a,pair<int,int>& b)
    {
        return a.second > b.second;
    }
    
    vector<int> sort_by_value(map<int,int>& m, int k)
    {
        vector<pair<int,int>> v;
        for(auto it: m)
            v.push_back(it);
        sort(v.begin(), v.end(), cmp);
        vector<int> ans;
        for(auto it : v)
        {
            if(k == 0)
                break;
            ans.push_back(it.first);
            k--;
        }
        return ans;
        
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        for(int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        return sort_by_value(m,k);
        
    }
};