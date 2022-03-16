class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        vector<int> v;
        int i = 0;
        for(auto it : pushed)
        {
            v.push_back(it);
            while(v.size() != 0 && v[v.size()-1] == popped[i])
            {
                v.pop_back();
                i++;
            }
        }
        return (v.size() == 0) ? true : false; 
    }
};