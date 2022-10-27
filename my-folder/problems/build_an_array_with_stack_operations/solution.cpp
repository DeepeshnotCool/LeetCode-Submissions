class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> v;
        int k = 1;
        for(int i = 0; i < target.size(); i++){
            if(target[i] > n){
                break;
            }

            for(int j = k; j <= n; j++){
                if(target[i] == j){
                    v.push_back("Push");
                    break;
                } else{
                    v.push_back("Push");
                    v.push_back("Pop");
                }

            }
            k = target[i] + 1;

        }
        return v;
    }
};