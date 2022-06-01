class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int size = nums.size();
        int arr[size];
        for(int i = 0; i < size; ++i){
            arr[i] = nums[i];
        }
        int result[size];
        partial_sum(arr, arr + size, result);
        vector<int> v(size);
        for(int i = 0; i < size; ++i){
            v[i] = result[i];
        }
        return v;
    }
};