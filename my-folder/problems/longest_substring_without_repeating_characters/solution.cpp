class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(255, -1);
        int maxi = 0, l = -1;
        for (int i = 0; i < s.size(); i++) {
            if (m[s[i]] > l)
                l = m[s[i]];
            m[s[i]] = i;
            maxi = max(maxi, i - l);
        }
        return maxi;
    }
};


