class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> v;
        for(auto it : ops){
            if(it == "+"){
                v.push_back(v[v.size()-1] + v[v.size()-2]);
            }
            else if(it == "D"){
                v.push_back(v[v.size()-1]*2);
            }
            else if(it == "C"){
                v.pop_back();
            }
            else
            {
                v.push_back(stoi(it));
            }
        }
        int sum = 0;
        for(auto it : v){
            sum += it; 
        }
        return sum;
    }
};