class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int maxi = INT_MIN;
        while(l < r){
            int area;
            if(height[l] < height[r]){
                area = height[l]*(r-l);
                l++;
            }
            else{
                area = height[r]*(r-l);
                r--;
            }
            maxi = max(area, maxi);
        }
        return maxi;
    }
};