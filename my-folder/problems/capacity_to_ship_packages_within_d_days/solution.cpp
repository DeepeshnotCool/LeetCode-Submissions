class Solution {
public:

    bool helper(int mid, vector<int> &weights, int days){
        int cap = mid;
        int reqDays = 1;
        int currWeight = 0;

        for(auto it : weights){
            if(currWeight + it > cap){
                currWeight = 0;
                reqDays++;
            }
            currWeight += it;
        }

        return (reqDays > days) ? false : true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        int ans = 0;
        while(l <= r){
            int mid = l + (r - l)/2;
            if(helper(mid, weights, days)){
                r = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};




