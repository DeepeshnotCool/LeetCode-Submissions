class Solution {
public:
    static bool cmp(string a,string b)
    {
        if(a.size() > b.size())
        {
            return true;
        }
        else if(a.size() < b.size())
            return false;
        for(int i = 0; i < a.size(); i++)
        {
            // if(a[i] == b[i])
            //     continue;
            if(a[i] > b[i])
                return true;
            else if(a[i] < b[i])
                return false;
        }
        return false;
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        return nums[k-1];
    }
};


