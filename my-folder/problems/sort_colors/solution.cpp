class Solution {
public:
    void sortColors(vector<int>& nums) {
        int countRed = 0, countWhite = 0, countBlue = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
                countRed++;
            if(nums[i] == 1)
                countWhite++;
            if(nums[i] == 2)
                countBlue++;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(i < countRed)
                nums[i] = 0;
            else if(i < countWhite + countRed)
                nums[i] = 1;
            else if(i < countBlue + countWhite + countRed)
                nums[i] = 2;
        }
    }
};