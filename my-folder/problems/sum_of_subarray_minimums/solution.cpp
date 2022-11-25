class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int ans = 0;
        stack<int> s;
        long mod = 1e9+7;
        s.push(-1);
        for(int i = 0; i < arr.size()+1; i++){
            int currVal = (i <= arr.size() - 1) ? arr[i] : 0;
            while(s.top() != -1 && currVal < arr[s.top()]){
                int index = s.top();
                s.pop();
                int j = s.top();
                int left = index - j;
                int right = i - index;
                long add = (left * right * (long)arr[index]) % mod;
                ans += add;
                ans %= mod;
            }
            s.push(i);
        }
        return ans;
    }
};

