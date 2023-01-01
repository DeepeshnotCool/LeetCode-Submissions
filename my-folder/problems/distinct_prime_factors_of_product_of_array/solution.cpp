class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        vector<int> vis(1001,0);
        vis[1] = 1;
        vis[0] = 1;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            int val = nums[i];
            if(val % 2 == 0){
                if(!vis[2])
                    ans++;
                while(val % 2 == 0) {
                    val /= 2;
                }
                vis[2] = 1;
                
            }
            for(int j = 3; j * j <= val; j += 2){
                if(val % j == 0){
                    if(!vis[j])
                        ans++;
                    while(val % j == 0){
                        val /= j;
                    }
                    vis[j] = 1; 
                }
            }
            if(val > 2){
                if(!vis[val])
                    ans++;
                vis[val] =1;
            }
        }
        return ans;
    }
};