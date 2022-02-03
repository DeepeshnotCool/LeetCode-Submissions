class Solution {
public:
    int countFrontZero(vector<int>& nums, int index)
    {
        int countF = 0;
        for(int i = index; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                nums[i] = -1;
            }
            else
                break;
            countF++;
        }
        return countF;
    }
    
    int countTrailZero(vector<int>& nums)
    {
        int countT= 0;
        int n = nums.size();
        for(int i = n-1; i >= 0; i--)
        {
            if(nums[i] == 0)
            {
                nums[i] = -1;
                countT++;
            }
            else 
                break;
        }
        return countT;
        
    }
    
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int count_front_zero = countFrontZero(nums,0);
        int count_trail_zero = countTrailZero(nums);
        if(count_front_zero)
        {
            for(int i = count_front_zero; i < n; i++)
            {
                nums[i-count_front_zero] = nums[i];
            }
        }
        int count = 0;
        for(int i = 0; i < n-count_trail_zero-count_front_zero-count; i++)
        {
            //cout<<nums[i]<<"_";
            if(nums[i] == 0)
            {
                int count_consecutive_zero = countFrontZero(nums,i);
                for(int j = i+count_consecutive_zero; j < n-count_trail_zero-count-count_front_zero; j++)
                {
                    //cout<<nums[j]<<"_";
                    nums[j-count_consecutive_zero] = nums[j];
                    //cout<<nums[j-count_consecutive_zero]<<"_";
                }
                // cout<<"i"<<i<<"-"<<count_consecutive_zero<<" ";
                count += count_consecutive_zero;
            }
            
        }
        //cout<<"\n"<<count;
        for(int i = n-count-count_trail_zero-count_front_zero; i < n; i++)
        {
            nums[i] = 0;
        }
    }
};