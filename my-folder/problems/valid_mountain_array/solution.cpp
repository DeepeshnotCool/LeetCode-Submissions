class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        
        if(arr.size() < 3)
            return false;
        int l = 0;
        int r = 1;
        bool flag = true;
        int count = 0;
        while(r != arr.size())
        {
            if(flag)
            {
                if(arr[l] < arr[r])
                {
                    l++;
                    r++;
                    count++;
                }
                else
                {
                    if(r == arr.size()-1 && arr[l] == arr[r])
                        return false;
                    flag = false;
                }
            }
            else
            {
                if(arr[l] > arr[r])
                {
                    l++;
                    r++;
                }
                else
                {
                    return false;
                }
            }
        }
        if(count == 0)
            return false;
        if(flag)
            return false;
        return true;
    }
};