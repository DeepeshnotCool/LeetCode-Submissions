class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int j = 0;
        vector<int> v;
        for(int i = 1; i <= 2000; i++)
        {
            if(v.size() < k) 
            {
                if(j <= arr.size()-1)
                {
                    if(arr[j] != i)
                        v.push_back(i);
                    else
                        j++;
                }
                else
                {
                    v.push_back(i);
                }
            }
            else
                break;
        }
        // for(auto x: v)
        //     cout<<x;
        return v[k-1];
    }
};