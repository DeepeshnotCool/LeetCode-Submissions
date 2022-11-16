class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int size = tasks.size();
        map<char, int> m;
        int maxi = 0;
        for(auto it: tasks){
            m[it]++;
            maxi = max(maxi, m[it]);
        }

        int ans = (maxi - 1) * (n + 1);
        for(auto it : m){
            if(it.second == maxi)
                ans++;
        }
        return max(ans, size);
    }
};
