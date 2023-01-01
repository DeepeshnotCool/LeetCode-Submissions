class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> vis(right+1,0);
        vis[0] = 1;
        vis[1] = 1;
        for(int i = 2; i <= right; i++){
            if(!vis[i]){
                int c=3;
                int x = i * 2;
                while(x <= right){
                    vis[x] = 1;
                    x=i*c;
                    c++;
                }
            }
        }
        vector<int> ans(2,-1);
        int diff = INT_MAX, curr, f=1;
        for(int i = left; i <= right; i++){
            if(!vis[i] && f==1){
                curr = i;
                f=0;
            }
            else if(!vis[i] && f==0){
                if( i - curr < diff){
                    ans[0] = curr;
                    ans[1] = i;
                    diff = i - curr;
                }
                curr = i;
            }
        }
        return ans;
    }
};